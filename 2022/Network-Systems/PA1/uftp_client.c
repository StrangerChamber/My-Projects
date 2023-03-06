#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

//John Blackburn January - February 13th, 2022
//Network Systems PA1 client file

#define BUFSIZE 16000

//bufsize discussed in lecture to be a max of 16k

/* 
 * error - wrapper for perror
 */
void error(char *msg) {
    perror(msg);
    exit(0);
}


int main(int argc, char **argv){
    /* variable declarations*/
    int so_error, sockfd, portno, n;
    int serverlen;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;
    char buf[BUFSIZE];
    char* command;
    char* filename;
    char filenames[BUFSIZE];
    char* filetype;
    FILE *fp;
    long numbytes;
    char input[2];
    struct timeval timeout;

    /*setting my timeout time to 5 seconds */

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;


    /* checking that the user entered a port and IP*/

    if (argc != 3) {
       fprintf(stderr,"usage: %s <IP address> <port>\n", argv[0]);
       exit(0);
    }

    hostname = argv[1];
    portno = atoi(argv[2]);

    /*creating the socket*/
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        error("Error opening socket");
    }
   

    /*get server DNS entry*/
    server = gethostbyname(hostname);
    if(server == NULL){
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);        
    }


    /* filling out the serveraddr struct*/
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
	  (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);
    
    /*setting the timeout structure */
    getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, sizeof(so_error));

    /* main service loop */
   
    while(1){
        
        /* get a message from the user */
        bzero(buf, BUFSIZE);
        printf("Please enter command to be sent to server: ");
        fgets(buf, BUFSIZE, stdin);


        /* send the message to the server */
        serverlen = sizeof(serveraddr);
        n = sendto(sockfd, buf, strlen(buf), 0, &serveraddr, serverlen);
        if (n < 0){ 
            error("ERROR in sendto");
        }
       
       
        command = strtok(buf, " ");//extract command type from user input
	
	strncpy(input, buf, 1);//breaking up each command sequence by the first char

	if(strcmp(input, "e") == 0){//exit sequence
			
		/*exit sequence simply receives confirmation from the server and ends the program */
	         n = recvfrom(sockfd, buf, sizeof(buf), 0, &serveraddr, &serverlen);
                 if (n < 0){
                        error("ERROR in recvfrom");
                 }
                 printf("Echo from server: %s\n", buf);

                if(strcmp(buf, "goodbye client") == 0){//client is exiting
                        break;//exit service loop effectively ending program
                }
	
	}else if(strcmp(input, "g") == 0){//get sequence
	
                /* get sequence breaks up the user input and adds the file to the client side*/		
        	filename = strtok(NULL, " ");
        	command[strcspn(command, "\n")] = 0;
        	filename[strcspn(filename, "\n")] = 0;
        	filetype = strtok(filename, ".");
        	filetype = strtok(NULL, ".");

		/*formatting the string so it can be used in fopen()*/
		snprintf(filenames, sizeof(filenames), "%s.%s", filename, filetype);


		n = recvfrom(sockfd, buf, sizeof(buf), 0, &serveraddr, &serverlen);
        	if (n < 0){ 
            		error("ERROR in recvfrom");
        	}

		printf("server has sent over the file data\n");

		if(strcmp(buf, "error opening file on server side") != 0){

			/* open file and write into it sequence*/
			fp = fopen(filenames, "w");
        
			if(fp == NULL){
        
				error("error opening new file on client side\n");
        
			}else{
        
				int fput = fputs(buf, fp);
        
				if(fput>0){
        
				}else{
        
					error("fputs failure");
        
				}
        
			}
		
			fclose(fp);
		}

	}else if(strcmp(input, "p") == 0){//put sequence


		/* open file then read contents and send over the buffer*/
        	filename = strtok(NULL, " ");
        	command[strcspn(command, "\n")] = 0;
        	filename[strcspn(filename, "\n")] = 0;
        	filetype = strtok(filename, ".");
        	filetype = strtok(NULL, ".");

        	
		/*formatting the string to be used by fopen*/
        	snprintf(filenames, sizeof(filenames), "%s.%s", filename, filetype);		
		fp = fopen(filenames, "r");
		if(fp == NULL){
			error("error opening file");
		}else{
			        
                	/* determine length of file then read into the buffer and send over to server*/
			fseek(fp, 0L, SEEK_END);

                        numbytes = ftell(fp);

                        fseek(fp, 0L, SEEK_SET);

                        fread(buf, sizeof(char), numbytes, fp);

                        fclose(fp);

                        printf("the file is ready to be sent to the server\n");

                        n = sendto(sockfd, buf, strlen(buf), 0, &serveraddr, serverlen);

                        if(n<0){
                                  error("error on sendto");
                        }

		}
			n = recvfrom(sockfd, buf, sizeof(buf), 0, &serveraddr, &serverlen);
                 	if (n < 0){
                        	error("ERROR in recvfrom");
                 	}
        
			printf("Server says: %s\n", buf);

		
	}else if(strcmp(input, "l") == 0){//ls sequence

		 /* ls sequence just receieves file names and prints them*/
       		 n = recvfrom(sockfd, buf, sizeof(buf), 0, &serveraddr, &serverlen);
       	
		 if (n < 0){ 
            		error("ERROR in recvfrom");
       		 }
       	
		 printf("all files in servers CWD: %s\n", buf);

	}else if(strcmp(input, "d") == 0){//delete sequence
		
		 /* delete sequence prints delete confirmation or failure*/
      		 n = recvfrom(sockfd, buf, sizeof(buf), 0, &serveraddr, &serverlen);

                 if (n < 0){
                        error("ERROR in recvfrom");
                 }

                 printf("Server says: %s\n", buf);


	}else{
		/*anything else input makes you input again*/
		printf("invalid command: please try again and make sure command is in lower case\n");
	}
        /*end of service loop */
    }
    return 0;
}


