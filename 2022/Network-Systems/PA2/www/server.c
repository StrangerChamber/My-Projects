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

//John Blackburn March 2022
// Network Systems PA2 HTTP Web Server File

/*10 CONNECTIONS CAN WAIT IN BACKLOG QUEUE IN LISTEN()*/
#define backlog 10 

#define BUFFERSIZE 16000 //CARRYING OVER BUFFERSIZE CHOICE FROM PA1 

/*ERROR WRAP*/
void error(char *msg){
	perror(msg);
	exit(0);
}

/*THREAD ROUTINE FUNCTION BODY IS BELOW MAIN()*/
void* threadRoutine(void *socket_desc);

/*MAIN FUNCTION*/
int main(int argc, char **argv){
	
	/*VARS USED IN MAIN()*/
	int status, newSockfd, sockfd, *new_sock;
	struct addrinfo hints, *servinfo;
	socklen_t addr_size;
	struct sockaddr_storage new_addr;	

	/*CHECK USER INPUT*/
	if(argc != 2){
		fprintf(stderr,"usage: %s <port>\n", argv[0]);
       		exit(0);
	}

	/*FILLING OUT ADDRINFO STRUCT FOR TCP USAGE*/
	memset(&hints, 0, sizeof(hints)); 
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM; 
	hints.ai_flags = AI_PASSIVE; 


	/*CALL GETADDRINFO()*/
	if((status = getaddrinfo(NULL, argv[1], &hints, &servinfo)) != 0){
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

	/*MAIN SERVICE LOOP*/
	while(1){
	
		/*CALL ACCEPT()*/
		newSockfd = accept(sockfd, (struct sockaddr *)&new_addr, &addr_size);
		if(newSockfd<0){
			error("error accepting connection on accept() function");
		}
		
		/*SET UP FOR PTHREAD_CREATE()*/
		pthread_t newThread;
		new_sock = malloc(1);
		*new_sock = newSockfd;

		/*CREATE THREAD AND SEND TO THREADROUTINE()*/
		if(pthread_create(&newThread, NULL, threadRoutine, (void*) new_sock) < 0){
			error("error creating thread");
			break;
		}
		
	}

	/*FREE ADDRINFO OF SERVER*/
	freeaddrinfo(servinfo);
	
	return 1; 
}



/*MAIN FUNCTIONALITY IS IN THIS FUNCTION*/
void* threadRoutine(void *socket_desc){
	
	/*VARS USED IN THREADROUTINE()*/
	int status, newSockfd, numBytesRecieved, bufHeaderSize, numBytesSent, seeker, numbytes, reader, closer, readInCount, statReturn, *new_sock;
	int protocolCheck = 1;
	struct addrinfo *servinfo;
	char buffer[BUFFERSIZE], buf[BUFFERSIZE], str[300];
	char * fileType, *fileT, *command, *url, *protocol, *temp;
	struct sockaddr_storage new_addr;	
	struct stat slat;
	FILE *fileptr;	
	char err400[] = "HTTP/1.1 400 Bad Request\r\n";
	char err403[] = "HTTP/1.1 403 Forbidden\r\n";
	char err404[] = "HTTP/1.1 404 Not Found\r\n";
	char err405[] = "HTTP/1.1 405 Method Not Allowed\r\n";
	char err505[] = "HTTP/1.1 505 HTTP Version Not Supported\r\n";

	/*SETTING UP NEW SOCKET FILE DESCRIPTOR TO BE USED THROUGHOUT FUNCTION*/
	newSockfd = *(int*)socket_desc;

	/*CALL RECV()*/
	numBytesRecieved = recv(newSockfd, buffer, BUFFERSIZE, 0);
	if(numBytesRecieved<0){
		error("error on recv");
	}else if(numBytesRecieved == 0){
		close(newSockfd);
	}

	temp = buffer;/*this allows me to use strsep with less trouble*/
	

	/*USE STRSEP() HERE TO BREAK UP CLIENT REQUEST AND FORMAT RETURN HEADERS*/
	command = strsep(&temp, " ");
	if(command == NULL){
		error("error separating the string into command using strsep");
	}

	url = strsep(&temp, " ");
	if(url == NULL){
		error("error parsing the url from the buffer using strsep");
	}

	protocol = strsep(&temp, " ");
	protocol = strsep(&protocol, "\r\n");//this removes everything after the http/1.x 
	if(protocol == NULL){
		error("error parsing out the protocol from the buffer using strsep");
	}

	/*CHECK HTTP VERSION HERE*/
	if(protocol[5]!= '1'){
		
		numBytesSent = send(newSockfd, err505, sizeof(err505) , 0);
		if(numBytesSent<0){
			error("error on send");
		}else if(numBytesSent<sizeof(err505)){

			printf("not all bytes from the header were sent, must send over the remaining amount now\n");
		}
		printf("505 error code sent back\n");
		protocolCheck = 0;

	}else if(protocol[7]!= '1' && protocol[7]!= '0'){
		
		numBytesSent = send(newSockfd, err505, sizeof(err505) , 0);
		if(numBytesSent<0){
			error("error on send");
		}else if(numBytesSent<sizeof(err505)){

			printf("not all bytes from the header were sent, must send over the remaining amount now\n");
		}
		printf("505 error code sent back\n");
		protocolCheck = 0;
	}

	if(protocolCheck == 0){
		/*IF WE SENT OVER 505 ERROR I DONT WANNA GO INTO THE COMMAND SEQUENCES*/
		close(newSockfd);
	}else{
		/*COME IN HERE WHEN PROTOCOL CHECK IS GOOD*/
		if((strcmp(command, "GET\0")) == 0){

			/*ADDING "." TO ANY GET REQUEST URL FOR FORMATTING*/	
			char path[300]= ".";
			strcat(path, url);

			/*NOTICED THAT ALL REQUESTS FOR THIS IMAGE DIDN'T INCLUDE THE CORRECT DIRECTORY SO I HELPED IT OUT A LITTLE BIT*/
			if(strcmp(path, "./favicon.ico\0") == 0){
				char pathZ[300] = "./www/favicon.ico";
				strcpy(path, pathZ);
			}

			/*Found this sequence to figure out content type at stackoverflow.com/questions/33745701/determining-the-filetype-of-a-file-in-c*/
			/*STAT FUNCTION AND STRUCT THAT IT FILLS OUT HELPS DETERMINE IF FILE OR DIRECTORY AND FILETYPE*/
			statReturn = stat(path, &slat);         
			if(statReturn <0){
				printf("stat() was unable to find the file\n");
			}

			if(S_ISREG(slat.st_mode)){
				//file is a byte stream
				
				/*THIS LOOP GETS THE FILE EXTENSION BY PARSING THE URL UNTIL WE REACH THE LAST BYTES AFTER A "."*/
				while((fileT = strsep(&url,".")) != NULL){
					fileType = fileT;
				}
			
				/*THIS IF ELSE SERIES FINDS THE CONTENT-TYPE HEADER FIELD*/
				if((strcmp(fileType, "html\0")) == 0){
					fileType = "text/html";
				}else if((strcmp(fileType, "txt\0")) == 0){
					fileType = "text/plain";
				}else if((strcmp(fileType, "png\0")) == 0){
					fileType = "image/png";
				}else if((strcmp(fileType, "gif\0")) == 0){
					fileType = "image/gif";
				}else if((strcmp(fileType, "jpg\0")) == 0){
					fileType = "image/jpg";
				}else if((strcmp(fileType, "css\0")) == 0){
					fileType = "text/css";
				}else if((strcmp(fileType, "js\0")) == 0){
					fileType = "application/javascript";
				}else if((strcmp(fileType, "ico\0")) == 0){/*FILE TYPE NOT MENTIONED IN WRITEUP BUT IS INCLUDED IN THE GIVEN FILE STRUCTURE SO I INCLUDED IT*/
					fileType = "image/x-icon";
				}else{
					/*UNRECOGNIZED FILETYPE*/
					fileType = NULL;
					error("the filetype was not recognized");
				}
			}else if(S_ISDIR(slat.st_mode)){
				//file is a directory
				/*HERE COMES THE CASE WHERE USER INPUT A DIRECTORY SO I NEED TO SEARCH FOR INDEX.HTML*/
				fileType = "text/html"; 
				strcat(path, "index.html");
			}   

			/*OPENING REQUESTED FILE FOR READING*/
			fileptr = fopen(path, "r");
			if(fileptr){
				
				/*HERE I NEED TO PUT THE STATUS CODE "(PROTOCOL) 200 OK\r\n" INTO BUFFER*/      
				strcat(protocol, " 200 OK\r\n");
				strcat(buf, protocol);  
				
				/*FORMAT CONTENT TYPE HEADER HERE*/
				char type[300] = "Content-Type: ";
				strcat(type, fileType);
				strcat(type, "\r\n");
				strcat(buf, type);

				/*SERIES TO DETERMINE AMOUNT OF BYTES IN FILE*/
				seeker = fseek(fileptr, 0L, SEEK_END);
				if(seeker != 0){
					error("error on fseek");
				}
				
				numbytes = ftell(fileptr);
				if(numbytes<0){
					error("error on ftell");
				}
				
				seeker = fseek(fileptr, 0L, SEEK_SET);
				if(seeker != 0){
						error("error on fseek");
				}
				
				/*CONTENT LENGTH HEADER FORMATTING*/
				char length[300] = "Content-Length: ";
				sprintf(str, "%d", numbytes);
				strcat(length, str);
				strcat(length, "\r\n\r\n");
				strcat(buf, length);

				/*I KNOW THIS IS GROSS BUT I WANT TO KNOW HOW MANY BYTES THE HEADER IS SO I CAN SEND THE RIGHT AMOUNT OVER TO THE BROWSER*/
				for(int i = 0;i<BUFFERSIZE;i++){
					if(buf[i] == '\n'){
						if(buf[i-1] == '\r'){
							if(buf[i-2] == '\n'){
								if(buf[i-3] == '\r'){
									bufHeaderSize = i+1;
									break;
								}
							}
						}
					}
				}

				/*SENDING OVER THE HEADERS */
				numBytesSent = send(newSockfd, buf, bufHeaderSize , 0);
				if(numBytesSent<0){
					error("error on send");
				}else if(numBytesSent<bufHeaderSize){
					printf("not all bytes from the header were sent\n");
				}


				/*THIS IF ELSE SEQUENCE IS FOR WHEN THE FILE IS LARGER THAN THE BUFFERSIZE*/
				if(BUFFERSIZE<numbytes){
					
					/*SENDING FILE DATA TO CLIENT IN CHUNKS*/
					while((reader = fread(buf, sizeof(char), BUFFERSIZE, fileptr)) > 0){
						numBytesSent = send(newSockfd, buf, reader, 0);
						if(numBytesSent<0){
							error("error on send");
						}
					}
					
					closer = fclose(fileptr);
					if(closer != 0){
						error("error on fclose");
					}

				}else{

					/*IF WE'RE IN HERE IT MEANS WE CAN SEND OVER EVERYTHING AT ONCE*/
					reader = fread(buf, sizeof(char), numbytes, fileptr);
					if(reader != numbytes){
						error("error on fread");
					}
					
					closer = fclose(fileptr);
					if(closer != 0){
						error("error on fclose");
					}

					/*SEND OVER FILE CONTENTS TO BROWSER*/
					numBytesSent = send(newSockfd, buf, reader, 0);
					if(numBytesSent<0){
						error("error on send");
					}else if(numBytesSent<numbytes){
						printf("not all bytes were sent");
					}else if(numBytesSent == numbytes){
						printf("%d bytes from the file were sent over\n", numBytesSent);
					}

				}
				close(newSockfd);
				bzero(buf, BUFFERSIZE);
			}else{
				
				/*THIS SEQUENCE IS WHEN FOPEN FAILED*/
				/*ERRNO IS SET WHEN FOPEN() FAILS*/
				if(errno == EACCES){
					
					/*PERMISSIONS ERROR*/
					numBytesSent = send(newSockfd, err403, sizeof(err403), 0);
					if(numBytesSent<0){
						error("error on send");
					}else if(numBytesSent<sizeof(err403)){
						printf("not all bytes were sent");
					}
					
				}else if(errno == ENOENT){
					
					/*FILE DOESN'T EXIST*/
					numBytesSent = send(newSockfd, err404, sizeof(err404), 0);
					if(numBytesSent<0){
						error("error on send");
					}else if(numBytesSent<sizeof(err404)){
						printf("not all bytes were sent");
					}

				}

				close(newSockfd);
				bzero(buf, BUFFERSIZE);

			}
		}else if((strcmp(command, "POST\0")) == 0){

			/*METHOD NOT ALLOWED*/
			numBytesSent = send(newSockfd, err405, sizeof(err405), 0);
			if(numBytesSent<0){
				error("error on send");
			}else if(numBytesSent<sizeof(err405)){
				printf("not all bytes were sent");
			}
			close(newSockfd);
		
		}else if((strcmp(command, "HEAD\0")) == 0){
			
			/*METHOD NOT ALLOWED*/
			numBytesSent = send(newSockfd, err405, sizeof(err405), 0);
			if(numBytesSent<0){
				error("error on send");
			}else if(numBytesSent<sizeof(err405)){
				printf("not all bytes were sent");
			}
			close(newSockfd);

		}else if((strcmp(command, "PUT\0")) == 0){
			
			/*METHOD NOT ALLOWED*/
			numBytesSent = send(newSockfd, err405, sizeof(err405), 0);
			if(numBytesSent<0){
				error("error on send");
			}else if(numBytesSent<sizeof(err405)){
				printf("not all bytes were sent");
			}
			close(newSockfd);
			
		}else if((strcmp(command, "DELETE\0")) == 0){
			
			/*METHOD NOT ALLOWED*/
			numBytesSent = send(newSockfd, err405, sizeof(err405), 0);
			if(numBytesSent<0){
				error("error on send");
			}else if(numBytesSent<sizeof(err405)){
				printf("not all bytes were sent");
			}
			close(newSockfd);

		}else if((strcmp(command, "CONNECT\0")) == 0){
			
			/*METHOD NOT ALLOWED*/
			numBytesSent = send(newSockfd, err405, sizeof(err405), 0);
			if(numBytesSent<0){
				error("error on send");
			}else if(numBytesSent<sizeof(err405)){
				printf("not all bytes were sent");
			}
			close(newSockfd);

		}else if((strcmp(command, "OPTIONS\0")) == 0){
			
			/*METHOD NOT ALLOWED*/
			numBytesSent = send(newSockfd, err405, sizeof(err405), 0);
			if(numBytesSent<0){
				error("error on send");
			}else if(numBytesSent<sizeof(err405)){
				printf("not all bytes were sent");
			}
			close(newSockfd);

		}else if((strcmp(command, "TRACE\0")) == 0){
			
			/*METHOD NOT ALLOWED*/
			numBytesSent = send(newSockfd, err405, sizeof(err405), 0);
			if(numBytesSent<0){
				error("error on send");
			}else if(numBytesSent<sizeof(err405)){
				printf("not all bytes were sent");
			}
			close(newSockfd);

		}else if((strcmp(command, "PATCH\0")) == 0){
			
			/*METHOD NOT ALLOWED*/
			numBytesSent = send(newSockfd, err405, sizeof(err405), 0);
			if(numBytesSent<0){
				error("error on send");
			}else if(numBytesSent<sizeof(err405)){
				printf("not all bytes were sent");
			}
			close(newSockfd);

		}else{
			
			/*BAD REQUEST ERROR*/
			numBytesSent = send(newSockfd, err400, sizeof(err400), 0);
			if(numBytesSent<0){
				error("error on send");
			}else if(numBytesSent<sizeof(err400)){
				printf("not all bytes were sent");
			}
			close(newSockfd);

		}
	}

	/*FREE MALLOCED MEM*/
	free(socket_desc);
	return 0;
}