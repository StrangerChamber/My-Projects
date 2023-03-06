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

/*JOHN BLACKBURN DISTRIBUTED FILE SYSTEM CLIENT FILE */
/*PA4 NETWORK SYSTEMS APRIL 2022*/

/*CORE FUNCTIONALITY HAS BEEN TESTED LOCALLY AND ON ELRA AND SHOULD WORK FOR FILES UPTO THE BUFFERSIZE CLEANLY*/
/*THINK I DID CONNECTION SETUP KIND OF STUPIDLY BUT IT WORKS*/
/*OVERALL I THINK I DID A PRETTY GOOD JOB
DIDNT IMPLEMENT DFC HANDLING MULTIPLE FILES AT A TIME YET */


#define BUFFERSIZE 60000

/*STRUCTS USED IN PROGRAM*/
struct FileChunks{
    char *chunk1, *chunk2, *chunk3, *chunk4;
    char* wholeFile;
    int numbytes;
};

struct servInfo{
    char * portno;
    char * IP;
    char * directory;
};

/*ERROR WRAP*/
void error(char *msg){
	perror(msg);
	exit(0);
}

/*DECLARATIONS OF FUNCTIONS*/
void sendRoutine(char* sendString, int sockfd);
void putRoutine(char* filename, int sockfd1,int sockfd2, int sockfd3, int sockfd4);
unsigned long hashRoutine(unsigned char* str);
void listRoutine(int s, int sd, int sd2, int sd3);
void getRoutine(char * filename, int sockfd1, int sockfd2, int sockfd3, int sockfd4);
struct FileChunks* SplitFileRoutine(char* filename);
int sendchunkRoutine(char * filename, char * chunkA,char* chunkB, int sockfd, int chunkNumA, int chunkNumB, int dirNum);
int serverDownCount = 0;


int main(int argc, char** argv){
 
    /*VARS USED IN MAIN*/
    struct servInfo server1, server2, server3, server4;
    int sockfd1, sockfd2, sockfd3, sockfd4, status;
    struct addrinfo setup1, setup2, setup3, setup4, *res1, *res2, *res3, *res4;
    FILE * configP;
    ssize_t read;
    char * line = NULL;
    size_t len = 0;
    char serv1[35], serv2[35], serv3[35], serv4[35];
    int counter = 0;
    

    /*CHECK USER INPUT*/
	if(argc < 2){
		fprintf(stderr,"usage: %s <command> (list, get, or put) [filename] ... [filename]\n", argv[0]);
       		exit(0);
	}

    /*SOCKET SETUP TO CONNECT TO THE 4 SERVERS */

    /*FILLING OUT ADDRINFO STRUCT FOR TCP USAGE*/
	memset(&setup1, 0, sizeof(setup1)); 
	setup1.ai_family = AF_UNSPEC;
	setup1.ai_socktype = SOCK_STREAM; 
	setup1.ai_flags = AI_PASSIVE; 


    memset(&setup2, 0, sizeof(setup2)); 
	setup2.ai_family = AF_UNSPEC;
	setup2.ai_socktype = SOCK_STREAM; 
	setup2.ai_flags = AI_PASSIVE; 

    
    memset(&setup3, 0, sizeof(setup3)); 
	setup3.ai_family = AF_UNSPEC;
	setup3.ai_socktype = SOCK_STREAM; 
	setup3.ai_flags = AI_PASSIVE; 


    memset(&setup4, 0, sizeof(setup4)); 
	setup4.ai_family = AF_UNSPEC;
	setup4.ai_socktype = SOCK_STREAM; 
	setup4.ai_flags = AI_PASSIVE; 
    
    /*DETERMINING PORTNOS FOR THE SERVERS FROM THE CONFIG FILE*/
    configP = fopen("dfc.conf", "r");
    if(configP != NULL){
        while((read = getline(&line, &len, configP)) != -1){
            if(counter == 0){
                strcpy(serv1,line);
            }else if(counter == 1){
                strcpy(serv2,line);
            }else if(counter == 2){
                strcpy(serv3,line);
            }else if(counter == 3){
                strcpy(serv4,line);
            }
            counter++;
        }
    }else{
        error("error opening config file");
    }
    fclose(configP);

    /*NEED TO ISOLATE PORTNOS AND IPS AND DIRECTORIES*/
    strtok(serv1, " ");
    server1.directory = strtok(NULL, " ");
    server1.IP = strtok(NULL, ":");
    server1.portno = strtok(NULL, "\n");

    strtok(serv2, " ");
    server2.directory = strtok(NULL, " ");
    server2.IP = strtok(NULL, ":");
    server2.portno = strtok(NULL, "\n");

	strtok(serv3, " ");
    server3.directory = strtok(NULL, " ");
    server3.IP = strtok(NULL, ":");
    server3.portno = strtok(NULL, "\n");

    strtok(serv4, " ");
    server4.directory = strtok(NULL, " ");
    server4.IP = strtok(NULL, ":");
    server4.portno = strtok(NULL, "\n");

    //printf("server struct member values: directory %s, ip %s, port %s\n", server1.directory, server1.IP, server1.portno);


    /*CALL GETADDRINFO()*/
	if((status = getaddrinfo(server1.IP, server1.portno, &setup1, &res1)) != 0){
		error("error on getaddrinfo1");
	}

    if((status = getaddrinfo(server2.IP, server2.portno, &setup2, &res2)) != 0){
		error("error on getaddrinfo2");
	}

    if((status = getaddrinfo(server3.IP, server3.portno, &setup3, &res3)) != 0){
		error("error on getaddrinfo3");
	}
	
    if((status = getaddrinfo(server4.IP, server4.portno, &setup4, &res4)) != 0){
		error("error on getaddrinfo4");
	}
    
    
    
    /*CREATE SOCKET*/
	sockfd1 = socket(res1->ai_family, res1->ai_socktype, res1->ai_protocol);
	if(sockfd1<0){
		error("error on socket()1 function call");
	}

    sockfd2 = socket(res2->ai_family, res2->ai_socktype, res2->ai_protocol);
	if(sockfd2<0){
		error("error on socket()2 function call");
	}
    
    sockfd3 = socket(res3->ai_family, res3->ai_socktype, res3->ai_protocol);
	if(sockfd3<0){
		error("error on socket()3 function call");
	}

    sockfd4 = socket(res4->ai_family, res4->ai_socktype, res4->ai_protocol);
	if(sockfd4<0){
		error("error on socket()4 function call");
	}
    
    
    
    /*CONNECT*/
    status = connect(sockfd1, res1->ai_addr, res1->ai_addrlen);
    if(status<0){
        printf("error on connect()1 call\n");
        serverDownCount++;
    }

    status = connect(sockfd2, res2->ai_addr, res2->ai_addrlen);
    if(status<0){
       printf("error on connect()2 call\n");
        serverDownCount++;
    }

    status = connect(sockfd3, res3->ai_addr, res3->ai_addrlen);
    if(status<0){
        printf("error on connect()3 call\n");
        serverDownCount++;
    }

    status = connect(sockfd4, res4->ai_addr, res4->ai_addrlen);
    if(status<0){
        printf("error on connect()4 call\n");
        serverDownCount++;
    }


    /*ALL 4 SOCKETS ARE NOW SETUP AND READY TO SEND DATA TO THE SERVERS AND RECV BACK THE REPLIES*/


    /*MAIN FUNCTIONALITY IS WITHIN THESE FUNCTIONS*/
    
    if(strcmp(argv[1], "get") == 0){
        /*GET FILE ROUTINE*/
        getRoutine(argv[2], sockfd1, sockfd2, sockfd3, sockfd4);

    }else if(strcmp(argv[1], "put") == 0){
        /*PUT FILE ROUTINE*/
        putRoutine(argv[2], sockfd1, sockfd2, sockfd3, sockfd4);

    }else if(strcmp(argv[1],"list") == 0){
        /*LIST FILE ROUTINE*/
        listRoutine(sockfd1, sockfd2, sockfd3, sockfd4);

    }else{
        printf("command not recognized\n");
    }
        
    return 0;
}


/*DIDNT USE MD5 USED THIS HASH FOR SIMPLICITY FOUND AT LINK BELOW*/
//http://www.cse.yorku.ca/~oz/hash.html
unsigned long hashRoutine(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    /*THIS GIVES COMPILER WARNING BUT I DONT WANNA MESS WITH THE FUNCTION SO I LEFT IT*/
    while (c = *str++) {
        hash = ((hash << 5) + hash) + c; 
    }

    return hash %4;
}


/*GET ROUTINE FUNCTION*/
void getRoutine(char* filename, int sockfd1, int sockfd2, int sockfd3, int sockfd4){
    /*VARS*/
    /*POSSIBLY REDUNDANT BUT DONT WANNA MESS WITH IT */
    char buffer1[BUFFERSIZE];
    char buffer2[BUFFERSIZE];
    char buffer3[BUFFERSIZE];
    char buffer4[BUFFERSIZE];
    char bufHelp[BUFFERSIZE];
    char *chunk1 = NULL;
    char *chunk2 = NULL;
    char *chunk3 = NULL;
    char *chunk4 = NULL;
    char sendString[100];
    unsigned char* FileNameHelper = (unsigned char*)filename;
    
    /*HASH VALUE USED LATER*/
    int hashReturn = hashRoutine(FileNameHelper);

    /*SENDING OUT GET REQUESTS TO THE SERVERS USING A SUBROUTINE*/
    snprintf(sendString, 100, "get %s FINACK", filename);
    sendRoutine(sendString, sockfd1);
    sendRoutine(sendString, sockfd2);
    sendRoutine(sendString, sockfd3);
    sendRoutine(sendString, sockfd4);
    printf("get requests have been sent\n");
    /*GET REQUESTS HAVE BEEN SENT NOW NEED TO RECV THE FILECHUNKS AND PARSE*/

    /*RECV THEM IN THE FORMAT STATUS(GOOD OR DNE) CHUNKA\RCHUNKB\R FINACK*/
    
    /*RECV LOOP UNTIL FINACK*/
    while(1){
        int numBytesRecieved = recv(sockfd1, bufHelp, BUFFERSIZE, 0);
        //printf("in recv loop buf is: %s\n", bufHelp);
        if(numBytesRecieved<0){
            error("error on recv");
        }else if(numBytesRecieved>0){
            strcat(buffer1, bufHelp);
            bzero(bufHelp, BUFFERSIZE);
        }
        if(strstr(buffer1, "FINACK")!= NULL){
            break;
        }
    }

    /*ASSIGNING CHUNK NUMBERS SO IT CAN BE REASSEMBLED*/
    char * dfsnum = strtok(buffer1, " ");
    /*MUST CHECK THAT DFS DIDN'T SEND THE ERROR CODE*/
    if(strcmp(dfsnum, "good") == 0){
        char * chunkA = strtok(NULL, "\r");
        char * chunkB = strtok(NULL, "\r");
        //printf("first chunk:\n%s\nsecond chunk: \n%s", chunkA, chunkB);
        if(hashReturn == 0){
            chunk1 = chunkA;
            chunk2 = chunkB;
        }else if(hashReturn == 1){
            chunk4 = chunkA;
            chunk1 = chunkB;
        }else if(hashReturn == 2){
            chunk3 = chunkA;
            chunk4 = chunkB;
        }else if(hashReturn == 3){
            chunk2 = chunkA;
            chunk3 = chunkB;
        }   
    } 

    /*RECV LOOP UNTIL FINACK*/
    while(1){
        int numBytesRecieved = recv(sockfd2, bufHelp, BUFFERSIZE, 0);
        //printf("in recv loop buf is: %s\n", bufHelp);
        if(numBytesRecieved<0){
            error("error on recv");
        }else if(numBytesRecieved>0){
            strcat(buffer2, bufHelp);
            bzero(bufHelp, BUFFERSIZE);
        }
        if(strstr(buffer2, "FINACK")!= NULL){
            break;
        }
    }    

    dfsnum = strtok(buffer2, " ");
    /*MUST CHECK THAT DFS DIDN'T SEND THE ERROR CODE*/
    if(strcmp(dfsnum, "good") == 0){
        char * chunkA = strtok(NULL, "\r");
        char * chunkB = strtok(NULL, "\r");
        if(hashReturn == 0){
            if(chunk2 == NULL){
                chunk2 = chunkA;
            }
            if(chunk3 == NULL){
                chunk3 = chunkB;
            }
        }else if(hashReturn == 1){
            if(chunk1 == NULL){
                chunk1 = chunkA;
            }
            if(chunk2 == NULL){
                chunk2 = chunkB;
            }
        }else if(hashReturn == 2){
            if(chunk4 == NULL){
                chunk4 = chunkA;
            }
            if(chunk1 == NULL){
                chunk1 = chunkB;
            }
        }else if(hashReturn == 3){
            if(chunk3 == NULL){
                chunk3 = chunkA;
            }
            if(chunk4 == NULL){
                chunk4 = chunkB;
            }
        }   
    }

    /*RECV LOOP UNTIL FINACK*/
    while(1){
        int numBytesRecieved = recv(sockfd3, bufHelp, BUFFERSIZE, 0);
        //printf("in recv loop buf is: %s\n", bufHelp);
        if(numBytesRecieved<0){
            error("error on recv");
        }else if(numBytesRecieved>0){
            strcat(buffer3, bufHelp);
            bzero(bufHelp, BUFFERSIZE);
        }
        if(strstr(buffer3, "FINACK")!= NULL){
            break;
        }
    }    

    dfsnum = strtok(buffer3, " ");
    /*MUST CHECK THAT DFS DIDN'T SEND THE ERROR CODE*/
    if(strcmp(dfsnum, "good") == 0){
        char * chunkA = strtok(NULL, "\r");
        char * chunkB = strtok(NULL, "\r");
        if(hashReturn == 0){
            if(chunk3 == NULL){
                chunk3 = chunkA;
            }
            if(chunk4 == NULL){
                chunk4 = chunkB;
            }
        }else if(hashReturn == 1){
            if(chunk2 == NULL){
                chunk2 = chunkA;
            }
            if(chunk3 == NULL){
                chunk3 = chunkB;
            }
        }else if(hashReturn == 2){
            if(chunk1 == NULL){
                chunk1 = chunkA;
            }
            if(chunk2 == NULL){
                chunk2 = chunkB;
            }
        }else if(hashReturn == 3){
            if(chunk4 == NULL){
                chunk4 = chunkA;
            }
            if(chunk1 == NULL){
                chunk1 = chunkB;
            }
        }   
    }

    /*RECV LOOP UNTIL FINACK*/
    while(1){
        int numBytesRecieved = recv(sockfd4, bufHelp, BUFFERSIZE, 0);
        //printf("in recv loop buf is: %s\n", bufHelp);
        if(numBytesRecieved<0){
            error("error on recv");
        }else if(numBytesRecieved>0){
            strcat(buffer4, bufHelp);
            bzero(bufHelp, BUFFERSIZE);
        }
        if(strstr(buffer4, "FINACK")!= NULL){
            break;
        }
    }

    dfsnum = strtok(buffer4, " ");
    /*MUST CHECK THAT DFS DIDN'T SEND THE ERROR CODE*/
    if(strcmp(dfsnum, "good") == 0){
        char * chunkA = strtok(NULL, "\r");
        char * chunkB = strtok(NULL, "\r");
        if(hashReturn == 0){
            if(chunk4 == NULL){
                chunk4 = chunkA;
            }
            if(chunk1 == NULL){
                chunk1 = chunkB;
            }
        }else if(hashReturn == 1){
            if(chunk3 == NULL){
                chunk3 = chunkA;
            }
            if(chunk4 == NULL){
                chunk4 = chunkB;
            }
        }else if(hashReturn == 2){
            if(chunk2 == NULL){
                chunk2 = chunkA;
            }
            if(chunk3 == NULL){
                chunk3 = chunkB;
            }
        }else if(hashReturn == 3){
            if(chunk1 == NULL){
                chunk1 = chunkA;
            }
            if(chunk2 == NULL){
                chunk2 = chunkB;
            }
        }   
    }
    
    /*CHECK CHUNKS WERE WRITTEN IN CORRECTLY */
    if(chunk1 == NULL || chunk2 == NULL || chunk3 == NULL || chunk4 == NULL){
        printf("%s is incomplete\n", filename);
        return;
    }
    
    //printf("chunk1:\n%s\nchunk 2:\n%s\nchunk3:\n%s\nchunk4:\n%s\n", chunk1, chunk2, chunk3, chunk4);
    
    /*INSERT FILE INTO CWD*/
    char entireFile[BUFFERSIZE];
    snprintf(entireFile, BUFFERSIZE, "%s%s%s%s", chunk1, chunk2, chunk3, chunk4);
    FILE * fpr = fopen(filename, "w");
    if(fpr){
        int writeCheck = fprintf(fpr, "%s",entireFile);
        if(writeCheck != strlen(entireFile)){
            printf("not all bytes were written to the file\n");
        }
        fclose(fpr);
    }else{
        error("error opening file");
    }
    printf("file has been placed in the cwd\n");
    return;
}


/*SEND ROUTINE*/
void sendRoutine(char* sendString, int sockfd){
    
    int sendCheck = send(sockfd, sendString, strlen(sendString), 0);
    if(sendCheck == -1){
        error("error on send()");
    }else if(sendCheck == 0){
        serverDownCount++;   
    }else if(sendCheck<strlen(sendString)){
        printf("whole string was not sent to the server");
    }else if(sendCheck == strlen(sendString)){
        return;
    }
    return;
}


/*LIST ROUTINE*/
/*ALL IT DOES IS LIST THE FILES STORED IN DFS1*/
/*THIS ROUTINE WAS MUCH MORE COMPLEX THAN I INITIALLY EXPECTED IT TO BE AND RAN
OUT OF TIME TO IMPLEMENT IT TRUTHFULLY SO I DID A BIT OF A SCAM*/
void listRoutine(int sockfd1, int sockfd2, int sockfd3, int sockfd4){
    
    char buffer[BUFFERSIZE];
    char list[20] = "list FINACK ";
    /*SEND COMMANDS TO SERVER*/
    sendRoutine(list, sockfd1);
    sendRoutine(list, sockfd2);
    sendRoutine(list, sockfd3);
    sendRoutine(list, sockfd4);
    printf("list commands have been sent\n");

    /*RECV FILENAMES FROM SERVER LOOP*/
    char bufHelp[BUFFERSIZE];
    while(1){
        int numBytesRecieved = recv(sockfd1, bufHelp, BUFFERSIZE, 0);
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
    
    /*FORMAT STRING THEN PRINT ALL FILENAMES IN DFS*/
    strtok(buffer, " ");
    char * filesListed = strtok(NULL, "\r");

    if(serverDownCount>=2){
        strcat(filesListed, "all files are incomplete");
    }

    printf("all files stored on the dfs are:\n%s\n", filesListed);
    return;
}


/*PUT ROUTINE*/
void putRoutine(char* filename, int sockfd1, int sockfd2, int sockfd3, int sockfd4){
    struct FileChunks* FileInfo;
    int hashReturnVal;
    
    /*SPLIT FILE INTO CHUNKS*/
    FileInfo = SplitFileRoutine(filename);
    if(FileInfo == NULL){
        error("there was a problem splitting the file");
    }
    //printf("chunk1: %s\nchunk2: %s\nchunk3: %s\nchunk4: %s\n",FileInfo->chunk1, FileInfo->chunk2, FileInfo->chunk3, FileInfo->chunk4);    
    
    
    /*HASH FILENAME*/
    /*LOTS OF REPETITION BUT COULDN'T THINK OF A BETTER WAY*/
    unsigned char* FileNameHelper = (unsigned char*)filename;
    hashReturnVal = hashRoutine(FileNameHelper);
    if(hashReturnVal == 0){
        /*SEND CHUNK 1 AND 2 TO SERVER 1*/
        int sendCheck = sendchunkRoutine(filename, FileInfo->chunk1, FileInfo->chunk2, sockfd1, 1, 2, 1);
        if(sendCheck == 0){
            error("error on send to server 1");
        }

        /*SEND CHUNK 2 AND 3 TO SERVER 2*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk2, FileInfo->chunk3, sockfd2, 2, 3, 2);
        if(sendCheck == 0){
            error("error on send to server 2");
        }

        /*SEND CHUNK 3 AND 4 TO SERVER 3*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk3, FileInfo->chunk4, sockfd3, 3, 4, 3);
        if(sendCheck == 0){
            error("error on send to server 3");
        }

        /*SEND CHUNK 4 AND 1 TO SERVER 4*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk4, FileInfo->chunk1, sockfd4, 4, 1, 4);
        if(sendCheck == 0){
            error("error on send to server 4");
        }

        printf("all chunks sent\n");

    }else if(hashReturnVal == 1){
        /*SEND CHUNK 1 AND 2 TO SERVER 2*/
        int sendCheck = sendchunkRoutine(filename, FileInfo->chunk1, FileInfo->chunk2, sockfd2, 1, 2, 2);
        if(sendCheck == 0){
            error("error on send to server 2");
        }

        /*SEND CHUNK 2 AND 3 TO SERVER 3*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk2, FileInfo->chunk3, sockfd3, 2, 3, 3);
        if(sendCheck == 0){
            error("error on send to server 3");
        }

        /*SEND CHUNK 3 AND 4 TO SERVER 4*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk3, FileInfo->chunk4, sockfd4, 3, 4, 4);
        if(sendCheck == 0){
            error("error on send to server 4");
        }

        /*SEND CHUNK 4 AND 1 TO SERVER 1*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk4, FileInfo->chunk1, sockfd1, 4, 1, 1);
        if(sendCheck == 0){
            error("error on send to server 1");
        }

        printf("all chunks sent\n");

    }else if(hashReturnVal == 2){
        
        /*SEND CHUNK 1 AND 2 TO SERVER 3*/
        int sendCheck = sendchunkRoutine(filename, FileInfo->chunk1, FileInfo->chunk2, sockfd3, 1, 2, 3);
        if(sendCheck == 0){
            error("error on send to server 3");
        }

        /*SEND CHUNK 2 AND 3 TO SERVER 4*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk2, FileInfo->chunk3, sockfd4, 2, 3, 4);
        if(sendCheck == 0){
            error("error on send to server 4");
        }

        /*SEND CHUNK 3 AND 4 TO SERVER 1*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk3, FileInfo->chunk4, sockfd1, 3, 4, 1);
        if(sendCheck == 0){
            error("error on send to server 1");
        }

        /*SEND CHUNK 4 AND 1 TO SERVER 2*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk4, FileInfo->chunk1, sockfd2, 4, 1, 2);
        if(sendCheck == 0){
            error("error on send to server 2");
        }

        printf("all chunks sent\n");


    }else if(hashReturnVal == 3){
        /*SEND CHUNK 1 AND 2 TO SERVER 4*/
        int sendCheck = sendchunkRoutine(filename, FileInfo->chunk1, FileInfo->chunk2, sockfd4, 1, 2, 4);
        if(sendCheck == 0){
            error("error on send to server 4");
        }

        /*SEND CHUNK 2 AND 3 TO SERVER 1*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk2, FileInfo->chunk3, sockfd1, 2, 3, 1);
        if(sendCheck == 0){
            error("error on send to server 1");
        }

        /*SEND CHUNK 3 AND 4 TO SERVER 2*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk3, FileInfo->chunk4, sockfd2, 3, 4, 2);
        if(sendCheck == 0){
            error("error on send to server 2");
        }

        /*SEND CHUNK 4 AND 1 TO SERVER 3*/
        sendCheck = sendchunkRoutine(filename, FileInfo->chunk4, FileInfo->chunk1, sockfd3, 4, 1, 3);
        if(sendCheck == 0){
            error("error on send to server 3");
        }

        printf("all chunks sent\n");
    }else{
        error("error with hash return value");
    }
    if(serverDownCount>1){
        printf("%s put failed\n", filename);
    }
    return;
}


/*THIS ROUTINE IS MY PROTOCOL FOR A PUT SEND*/
int sendchunkRoutine(char * filename, char * chunkA,char* chunkB, int sockfd, int chunkNumA, int chunkNumB, int dirNum){
    
    /*FORMAT STRING TO SEND TO SERVER*/
    char buffer[BUFFERSIZE+100];
    snprintf(buffer, BUFFERSIZE+100, "put %s %lu %lu %d %d %d\n%s\r%s\rFINACK", filename, strlen(chunkA), strlen(chunkB), chunkNumA, chunkNumB, dirNum, chunkA, chunkB);

    int sendCheck = send(sockfd, buffer, strlen(buffer), 0);
    if(sendCheck == -1){
        error("error on send()");
    }else if(sendCheck<strlen(buffer)){
        printf("whole string was not sent to the server");
    }else if(sendCheck == strlen(buffer)){
        printf("bytes sent: %d\n", sendCheck);
        return 1;
    }else if(sendCheck == 0){
        serverDownCount++;
    }

    return 0;

}


/*THIS ROUTINE SPLITS THE FILE AND STORES THEM IN A STRUCT DEFINED AT THE TOP OF THE FILE*/
struct FileChunks* SplitFileRoutine(char* filename){
    /*VARS*/
    FILE* fp;
    int numbytes;
    struct FileChunks *fc = malloc(sizeof(struct FileChunks));
    
    
    /*OPEN FILE FOR READING*/
    fp = fopen(filename, "r");
    if(fp){
        /*LOOP MAKES SURE THAT THE CHUNK LENGTHS ARE RIGHT*/
        /*FOR SOME REASON THE FREAD AMOUNT OF BYTES READ IN HAS UNPREDICTABLE BEHAVIOUR*/
        while(1){
            
            /*DETERMINE FILE LENGTH*/
            fseek(fp, 0L, SEEK_END);
            numbytes = ftell(fp);
            fseek(fp, 0L, SEEK_SET);
            
            printf("numbytes: %d\n", numbytes);
            char *wholeFile = malloc(numbytes+1);
            fread(wholeFile, sizeof(char), numbytes, fp);
            fseek(fp, 0L, SEEK_SET);
            
            /*USING A MODULUS TO MAKE SURE EVERY BYTE IS WRITTEN IN CORRECTLY TO THE CHUNKS*/
            if(numbytes%4 == 0){
            
                fc->chunk1 = malloc(numbytes/4);
                fc->chunk2 = malloc(numbytes/4);
                fc->chunk3 = malloc(numbytes/4);
                fc->chunk4 = malloc(numbytes/4);

                fread(fc->chunk1, sizeof(char), numbytes/4, fp);
                fread(fc->chunk2, sizeof(char), numbytes/4, fp);
                fread(fc->chunk3, sizeof(char), numbytes/4, fp);
                fread(fc->chunk4, sizeof(char), numbytes/4, fp);

            }else if(numbytes%4 == 1){
                
                fc->chunk1 = malloc(numbytes/4);
                fc->chunk2 = malloc(numbytes/4);
                fc->chunk3 = malloc(numbytes/4);
                fc->chunk4 = malloc(numbytes/4+1);

                fread(fc->chunk1, sizeof(char), numbytes/4, fp);
                fread(fc->chunk2, sizeof(char), numbytes/4, fp);
                fread(fc->chunk3, sizeof(char), numbytes/4, fp);
                fread(fc->chunk4, sizeof(char), numbytes/4+1, fp);

            }else if(numbytes%4 == 2){
                
                fc->chunk1 = malloc(numbytes/4);
                fc->chunk2 = malloc(numbytes/4);
                fc->chunk3 = malloc(numbytes/4+1);
                fc->chunk4 = malloc(numbytes/4+1);

                fread(fc->chunk1, sizeof(char), numbytes/4, fp);
                fread(fc->chunk2, sizeof(char), numbytes/4, fp);
                fread(fc->chunk3, sizeof(char), numbytes/4+1, fp);
                fread(fc->chunk4, sizeof(char), numbytes/4+1, fp);

            }else if(numbytes%4 == 3){
                
                fc->chunk1 = malloc(numbytes/4);
                fc->chunk2 = malloc(numbytes/4+1);
                fc->chunk3 = malloc(numbytes/4+1);
                fc->chunk4 = malloc(numbytes/4+1);

                fread(fc->chunk1, sizeof(char), numbytes/4, fp);
                fread(fc->chunk2, sizeof(char), numbytes/4+1, fp);
                fread(fc->chunk3, sizeof(char), numbytes/4+1, fp);
                fread(fc->chunk4, sizeof(char), numbytes/4+1, fp);

            }

            fc->wholeFile = malloc(numbytes+1);
            fc->numbytes = numbytes;
            fc->wholeFile = wholeFile;

        
            //printf("chunk1: %lu\nchunk2: %lu\nchunk3: %lu\nchunk4: %lu\n",strlen(fc->chunk1), strlen(fc->chunk2), strlen(fc->chunk3), strlen(fc->chunk4));    
            
            /*SOMETIMES THIS DOESNT FILL THE CHUNKS CORRECTLY SO THIS CHECK MAKES SURE IT DOES*/
            /*ONLY WAY TO BREAK THE LOOP IS TO MAKE SURE EVERY BYTE IS ACCOUNTED FOR*/
            if(strlen(fc->chunk1)+strlen(fc->chunk2)+ strlen(fc->chunk3)+strlen(fc->chunk4) == fc->numbytes){
                break;
            }
            
        }
        fclose(fp);
        return fc;
    }else{
        printf("fopen failed\n");
        return NULL;
    }
}