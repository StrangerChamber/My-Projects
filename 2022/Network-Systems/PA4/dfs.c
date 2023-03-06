#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <pthread.h>
#include <dirent.h>

/*JOHN BLACKBURN SERVER FILE FOR DISTRIBUTED FILE SYSTEM FOR PA4 NETWORK SYSTEMS*/
/*APRIL 2022*/

/*SERVER FILE IS MUCH MORE SIMPLISTIC THAN THE CLIENT*/
/*RUNS IN INFINITE LOOP AND SERVICES GET, PUT, AND LIST REQUESTS CLEANLY*/
/*IF I HAD MORE TIME I WOULD PUT THE COMMAND SEQUENCES INTO FUNCTIONS*/
/*COULD BE MORE ORGANIZED BUT IT WORKS*/
/*USED FORK() TO HANDLE MULTIPLE CONNECTIONS RATHER THAN PTHREAD CREATE THIS TIME*/
/*SHOULD CLEANUD USE OF DIRNUM AND ARGV[1]*/


#define backlog 10 
#define BUFFERSIZE 60000


/*STRUCT USED*/
struct FileInfo{
    char * command, * filename;
    char* firstChunkLength, *secondChunkLength, *dirNum, *firstChunkNum, *secondChunkNum;
    char* firstchunk;
    char* secondchunk;
};


/*ERROR WRAP*/
void error(char *msg){
	perror(msg);
	exit(0);
}

int main(int argc, char** argv){

    /*VARS USED IN MAIN()*/

    char buffer[BUFFERSIZE];
    char bufHelp[BUFFERSIZE];
    char dirName[5];
    int numBytesRecieved;
    char filePath[25];
	int status, newSockfd, sockfd;
	struct addrinfo hints, *servinfo;
	socklen_t addr_size;
	struct sockaddr_storage new_addr;
    int fileCount = 0;
    FILE * fp;
    
	/*CHECK USER INPUT*/
	if(argc != 3){
		fprintf(stderr,"usage: %s <./dfs#> <port>\n", argv[0]);
       		exit(0);
	}

    /*MAKE THE DIRECTORY TO STORE THE FILES IN*/
    int mkdirCheck = mkdir(argv[1], 0700);
    if(mkdirCheck == -1){
        printf("error making directory; ignore this message if directory already created\n");
    }


	/*FILLING OUT ADDRINFO STRUCT FOR TCP USAGE*/
	memset(&hints, 0, sizeof(hints)); 
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM; 
	hints.ai_flags = AI_PASSIVE; 


	/*CALL GETADDRINFO()*/
	if((status = getaddrinfo(NULL, argv[2], &hints, &servinfo)) != 0){
		error("error on getaddrinfo");
	}

	/*CREATE SOCKET*/
	sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	if(sockfd<0){
		error("error on socket() function call");
	}

	/*BIND TO PORT*/
	if(bind(sockfd, servinfo->ai_addr, servinfo->ai_addrlen)<0){
		error("error binding");
	}

	/*CALL LISTEN()*/
	if(listen(sockfd, backlog)<0){
		error("error on listen");
	}

    while(1){

        bzero(buffer, BUFFERSIZE);
        /*CALL ACCEPT()*/
        newSockfd = accept(sockfd, (struct sockaddr *)&new_addr, &addr_size);
        if(newSockfd<0){
            error("error accepting connection on accept() function");
        }

        int forkReturn = fork();
        
        /*THIS IS THE CHILD THREAD THAT WILL HANDLE THE ACCEPTED CONNECTION*/
        if(forkReturn == 0){
            /*RECV DATA LOOP UNTIL RECV FINACK*/
            while(1){
                numBytesRecieved = recv(newSockfd, bufHelp, BUFFERSIZE, 0);
                //printf("in recv loop buf is: %s\n", bufHelp);
                if(numBytesRecieved<0){
                    error("error on recv");
                }else if(numBytesRecieved>0){
                    strcat(buffer, bufHelp);
                    bzero(bufHelp, BUFFERSIZE);
                }
                if(strstr(buffer, "FINACK")!= NULL){
                    break;
                }
            }

            printf("numbytes received is: %ld\n", strlen(buffer));

            char * command = strtok(buffer, " ");
            /*PUT SEQUENCE*/
            if(strcmp(command, "put") == 0){
                
                /*PARSE THE REST OF THE DATA SENT OVER WHEN I KNOW ITS A PUT REQUEST*/
                char * filename = strtok(NULL, " ");
                char* chunkALength = strtok(NULL, " ");
                char* chunkBLength = strtok(NULL, " ");
                strtok(NULL, " ");
                strtok(NULL, " ");
                char* dirNum = strtok(NULL, "\n");
                char* chunkA = strtok(NULL, "\r");
                char* chunkB = strtok(NULL, "\r");
                //printf("command: %s\nfilename: %s\nfirst chunk length: %s\nsecond chunk length: %s\nfirst chunk num: %s\nsecond chunk num: %s\ndir num: %s\nchunkA: %s\nchunkB: %s\n", command, filename, chunkALength, chunkBLength, chunkANum, chunkBNum, dirNum, chunkA, chunkB);
                
                snprintf(dirName, 5, "dfs%s", dirNum);
                
                /*HAVE ALL DATA I NEED NOW TO INSERT THE FILES INTO THE DFS*/
                snprintf(filePath, 25, "./dfs%s/%s", dirNum, filename);
                char* fileHelper = filePath;
                fp = fopen(fileHelper, "w");
                if(fp!=NULL){
                    int writeCheck = fprintf(fp, "%s\r%s\r", chunkA, chunkB);
                    if(writeCheck != atoi(chunkALength) + atoi(chunkBLength)){
                        //printf("not all bytes were written to the file\n");
                    }
                    fclose(fp);
                }else{
                    error("error on fopen");
                }
                printf("file has been written into the dfs\n");
                bzero(buffer,BUFFERSIZE);

            }else if(strcmp(command, "get") == 0){
                /*GET SEQUENCE*/

                /*FIND FILE, OPEN, READ IN, SEND OUT*/
                char * filename = strtok(NULL, " ");
                char filepath [25];
                snprintf(filepath, 25, "%s/%s", argv[1], filename);
                char* fileHelper = filepath;
                FILE * fp = fopen(fileHelper, "r");
                if(fp!=NULL){
                    
                    int seeker = fseek(fp, 0L, SEEK_END);
                    if(seeker != 0){
                        error("error on fseek");
                    }
                    
                    int numbytes = ftell(fp);
                    if(numbytes<0){
                        error("error on ftell");
                    }
                    
                    seeker = fseek(fp, 0L, SEEK_SET);
                    if(seeker != 0){
                        error("error on fseek");
                    }

                    char buf[numbytes];
                    fread(buf, 1, numbytes, fp);
                    char buffer[numbytes+50];
                    snprintf(buffer, numbytes+50, "good %s FINACK", buf);

                    int sendCheck = send(newSockfd, buffer, strlen(buffer), 0);
                    if(sendCheck == -1){
                        error("error on send()");
                    }else if(sendCheck<strlen(buffer)){
                        printf("whole string was not sent to the server\n");
                    }else{
                        printf("buffer has been sent\n");
                    }

                    fclose(fp);
                }else{
                    /*FILE DNE IN DFS*/
                    char buffer[25];
                    snprintf(buffer, 25, "DNE %s FINACK", argv[1]);
                    int sendCheck = send(newSockfd, buffer, strlen(buffer), 0);
                    if(sendCheck == -1){
                        error("error on send()");
                    }else if(sendCheck<strlen(buffer)){
                        printf("whole string was not sent to the server\n");
                    }  
                } 

                printf("get routine complete; file has been sent back\n");

            }else if(strcmp(command, "list") == 0){
                /*LIST ROUTINE*/

                DIR *d;
                char buffer[BUFFERSIZE];
                struct dirent *dir;
                
                /*OPEN DIRECTORY, STORE ALL FILENAMES, SEND BACK*/
                d = opendir(argv[1]);
                if(d){
                    
                    while((dir = readdir(d)) != NULL){
                        fileCount++;
                        strcat(buffer, dir->d_name);
                        strcat(buffer, " ");
                    }
                    
                    closedir(d);
                    char sendString[1000];
                    snprintf(sendString, 1000, "%d %s\r FINACK", fileCount, buffer);
                    fileCount = 0;
                    char* buffers = sendString;
                    
                    int sendCheck = send(newSockfd, buffers, strlen(buffers), 0);
                    if(sendCheck == -1){
                        error("error on send()");
                    }
                    printf("list has been sent back\n");
                }else{
                    /*COULDNT OPEN DIRECTORY*/
                    char buffer[] = "DNE NULL\r FINACK";
                    int sendCheck = send(newSockfd, buffer, strlen(buffer), 0);
                    if(sendCheck == -1){
                        error("error on send()");
                    }
                }
                bzero(buffer, BUFFERSIZE);

            }else{
                /*SENT OVER SOMETHING OTHER THAN GET, PUT, OR LIST*/
                printf("invalid command\n");
            }
            return 0;
        }
    }
    return 0;
}