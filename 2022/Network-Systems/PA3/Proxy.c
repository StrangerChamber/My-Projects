#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <pthread.h>

//John Blackburn April 2022
// Network Systems PA3 HTTP Proxy File

/*Procrastinated this assignment such that i wasn't able to get the full functionality implemented, however the core is there, it 
works as a successful proxy for http connections, and has a blocklist that works. I needed more time to figure the hashing and caching but 
I understand the concepts just didn't have enough time in the end to fully understand their implementations. I left in what my caching code
but commented them out so it wouldn't mess with the proxy. I was close but did not get all the way. Was able to connect to many http sites
using the foxyproxy extension in firefox.*/

/*10 CONNECTIONS CAN WAIT IN BACKLOG QUEUE IN LISTEN()*/
#define backlog 10 

#define BUFFERSIZE 16000 //ARBITRARY CHOICE

/*ERROR WRAP*/
void error(char *msg){
	perror(msg);
	exit(0);
}

/*HASH FUNCTION USED FOR CACHING*/
/* FOUND AT http://www.cse.yorku.ca/~oz/hash.html*/
/*DIDNT END UP GETTING TO ACTUALLY IMPLEMENT THIS*/
unsigned long hash(unsigned char *str){
    unsigned long hash = 5381;
    int c = 0;
    while (c == *str++){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}



/*THREAD ROUTINE FUNCTION BODY IS BELOW MAIN()*/
void* threadRoutine(void *socket_desc);

/*MAIN FUNCTION*/
int main(int argc, char **argv){
	
	/*VARS USED IN MAIN()*/
	int status, newCtoPSockfd, CtoPsockfd, *new_sock;
	struct addrinfo CtoP, *proxyinfo;
	socklen_t addr_size;
	struct sockaddr_storage new_addr;	

	/*CHECK USER INPUT*/
	if(argc != 3){
		fprintf(stderr,"usage: %s <port> <cache Timeout in Seconds>\n", argv[0]);
       		exit(0);
	}

	/*FILLING OUT PROXY ADDRINFO STRUCT FOR TCP USAGE*/
	memset(&CtoP, 0, sizeof(CtoP)); 
	CtoP.ai_family = AF_UNSPEC;
    CtoP.ai_socktype = SOCK_STREAM; 
	CtoP.ai_flags = AI_PASSIVE; 

	/*CALL GETADDRINFO()*/
	if((status = getaddrinfo(NULL, argv[1], &CtoP, &proxyinfo)) != 0){
		error("error on getaddrinfo");
	}

	/*CREATING CLIENT TO PROXY SOCKET*/
	CtoPsockfd = socket(proxyinfo->ai_family, proxyinfo->ai_socktype, proxyinfo->ai_protocol);
	if(CtoPsockfd<0){
		error("error on socket() function call");
	}

	/*BIND TO PORT*/
	if(bind(CtoPsockfd, proxyinfo->ai_addr, proxyinfo->ai_addrlen)<0){
		error("error binding");
	}
    
    /*FREE ADDRINFO OF PROXY*/
	freeaddrinfo(proxyinfo);

	/*CALL LISTEN()*/
	if(listen(CtoPsockfd, backlog)<0){
		error("error on listen");
	}

	/*MAIN SERVICE LOOP*/
    int threadcount = 1;
	while(1){
	
		/*CALL ACCEPT()*/
		newCtoPSockfd = accept(CtoPsockfd, (struct sockaddr *)&new_addr, &addr_size);
		if(newCtoPSockfd<0){
			error("error accepting connection on accept() function");
		}
		
		/*SET UP FOR PTHREAD_CREATE()*/
		pthread_t newThread;
		new_sock = malloc(1);
		*new_sock = newCtoPSockfd;

        printf("threadcount: %d\n", threadcount);
		/*CREATE THREAD AND SEND TO THREADROUTINE()*/
		if(pthread_create(&newThread, NULL, threadRoutine, (void*) new_sock) < 0){
			error("error creating thread");
			break;
		}	
        threadcount++;
	}
	return 1; 
}



/*MAIN FUNCTIONALITY IS IN THIS FUNCTION*/
void* threadRoutine(void *socket_desc){
    /*VARS USED IN THIS FUNCTION*/
    int recvCheck;
    char buffer[BUFFERSIZE];
    //FILE * fileP;
    int sockfd = *(int*) socket_desc;
    char command[100];
    char url[300];
    char version[100];
    char urlforsend[300];
    char helper_url[300];
    FILE * fp;
    char host[300];
    char *portno;
    int count = 0;
    int check = 0;
    portno = "80";
    char err400[] = "400 Bad Request\r\n";
    char err403[] = "403 Forbidden\r\n";
    char err404[] = "404 Not Found\r\n";
    
    /* SET UP SECOND SOCKET*/
    
    struct addrinfo hints, *res;
    int Secondsockfd;
    int numBytesSent;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    /*RECV DATA FROM CLIENT*/
    recvCheck = recv(sockfd, buffer, BUFFERSIZE, 0);
    if(recvCheck < 0){
        error("error on recv");
    }

    /*PARSE DATA*/
    sscanf(buffer, "%s %s %s", command, url, version);

    printf("buffer recieved:\n%s", buffer);

    /*ONLY SUPPORT GET REQUESTS*/
    if((strcmp(command, "GET\0")) != 0){
        numBytesSent = send(sockfd, err400, sizeof(err400), 0);
        if(numBytesSent<0){
            error("error on send");
        }
        close(sockfd);
        return 0;
    }


    strcpy(urlforsend, url); //STORING FOR LATER USE 
    strcpy(helper_url, url);

    char* temp_url = url;
    char* temp = strtok(temp_url, ":");
    int length = strlen(temp_url);
    while(count<length){
        if(strcmp(&temp_url[count], ":") == 0){
            check = 1;
        }
        count++;
    }
    if(check == 1){
        temp = strtok(temp_url, ":");
        portno = temp_url;
    }

    /*PULLING OUT HOST NAME FROM URL*/
    char* final_url = strstr(helper_url, "//");
    final_url = final_url+2;
    final_url = strtok(final_url, "/");
    char * sfinal_url = strtok(final_url, ":");
    portno = final_url;
    strcpy(host,sfinal_url);
    printf("portno : %s", portno);

    /*CHECK SERVER EXISTS*/
    printf("host right before its passed to gethostbyname: %s\n", host);
    struct hostent *hs = gethostbyname(host);
    if(hs == NULL){
        herror("error on gethostbyname");
        numBytesSent = send(sockfd, err404, sizeof(err404), 0);
        if(numBytesSent<0){
            error("error on send");
        }
        close(sockfd);
        return 0;
    }
    printf("after gethostbyname\n");

    /*SET UP ADDRINFO STRUCT*/

    int addrCheck = getaddrinfo(url, portno, &hints, &res);
    if(addrCheck <0){
        error("error on getaddrinfo");
    }
    printf("after gethostbyname\n");

    /*BLOCKLIST CHECK*/
    char* IPbuffer = inet_ntoa(*((struct in_addr*)hs->h_addr_list[0]));
    fp = fopen("blocklist", "r");
    if(fp){
        char* line = NULL;
        size_t len = 0;
        ssize_t reader;
        int check = 1;
        while((reader = getline(&line, &len, fp)) != -1){
            check = strcmp(line, IPbuffer);
            check = strcmp(line, host);
            if(check == 0){
                break;
            }
        }
        fclose(fp);
        if(check == 0){
            numBytesSent = send(sockfd, err403, sizeof(err403), 0);
            if(numBytesSent<0){
                error("error on send");
            }
            close(sockfd);
            printf("a match was found on the blocklist, error 403 has been sent to the client, and the socket has been closed\n");
            return 0;
        }
    }else{
            printf("error opening blocklist\n");
    }

printf("after gethostbyname\n");

    /*SET THE SECOND SOCKET */
    printf("beforesocke\n");
    Secondsockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    printf("aftersocket\n");
    if(Secondsockfd<0){
        error("error on socket()");
    }
    printf("after gethostbyname\n");

    /*CONNECT TO SECOND SOCKET*/
    int connectCheck = connect(Secondsockfd, res->ai_addr, res->ai_addrlen);
    if(connectCheck == -1){
        error("error on connect()");
    }

printf("after gethostbyname\n");
    /*SETTING UP TIMEOUT*/
    struct timeval timeout;
    timeout.tv_sec = 5;
    setsockopt(Secondsockfd, SOL_SOCKET, SO_RCVTIMEO, (struct timeval*)&timeout, sizeof(struct timeval));

printf("after gethostbyname\n");
    /*DATA IS READY TO BE SENT TO SERVER*/

    /*BUT FIRST CHECK TO SEE IF FILE IS IN THE CACHE*/
    
    //unsigned long hashed = hash((unsigned char*)urlforsend);
    //char hashedaschar[10];
    //sprintf(hashedaschar, "%lu", hashed);
    /*CHECK IF FILE EXISTS WITH FOPEN
    CANNOT GET CACHING TO WORK PROPERLY SO WILL NOT INCUDE THIS SECTION

    FILE * filePointer = fopen((char*)urlforsend, "r");
    if(filePointer){
        CANNOT FIGURE OUT TIMEOUT SO NOT GOING TO IMPLEMENT IT
        printf("going into cache fopen\n");
        char tempBuffer[100];
        while(fgets(tempBuffer, 100, filePointer)!=NULL){
            numBytesSent = send(sockfd, tempBuffer, 100, 0);
            if(numBytesSent<=0){
                error("error on send");
            }
        }
        fclose(filePointer);
        close(sockfd);
        close(Secondsockfd);
        return 0;
    }*/


    /*SEND OVER WHAT WAS SENT BY THE CLIENT*/
    numBytesSent = send(Secondsockfd, buffer, sizeof(buffer), 0);
    if(numBytesSent<0){
        error("error on send");
    } 

    /*GET RESPONSE BACK FROM SERVER*/
    //char filecontents[100000];
    memset(buffer, 0, BUFFERSIZE);
    /*LOOP THAT RUNS UNTIL RECV GETS NOTHING BACK FROM SERVER*/
    while(1){
        recvCheck = read(Secondsockfd, buffer, BUFFERSIZE);
        if(recvCheck<=0){
            break;
        }
        /*STORING EVERYTHING SENT BACK SO IT CAN BE CACHED*/
        //strcat(filecontents, buffer);
        /*FORWARD REPLY TO CLIENT*/
        numBytesSent = send(sockfd, buffer, recvCheck , 0);
        if(numBytesSent<=0){
            break;
        }
    }

    /*CLOSE SOCKETS*/
    close(Secondsockfd);
    close(sockfd);

    /*STORE WHAT WAS SENT OVER SO IT CAN BE CACHED IN THE FUTURE*/

    /*CANNOT GET WORKING PROPERLY*/
    
    /*DOESNT CACHE DYNAMIC CONTENT WITH THIS CHECK*/
    /*
    char * checker = strchr(urlforsend, '?');
    if(checker == NULL){
        
        CALL HASH FUNCTION THEN FORMAT THAT INTO A NEW FILE WITH THE HASH VALUE AS THE FILENAME
        
        //unsigned long hashed = hash((unsigned char*)urlforsend);
        //char hasheda[10];
        //sprintf(hasheda, "%lu", hashed);

        fileP = fopen((char*)urlforsend, "w");
        if(fileP){
            printf("inside fileP\n");
            fputs(filecontents, fileP);
        }else{
            printf("error on fopen");
        }
        fclose(fileP);
    }*/
    free(socket_desc);
    return 0;
}