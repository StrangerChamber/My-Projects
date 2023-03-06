#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>//needed for ls command

//John Blackburn January-February 13th, 2022
//Network Systems PA1 server file

#define BUFSIZE 16000 //buffer size discussed in lecture


/*error wrapper */
void error(char *msg){
    perror(msg);
    exit(1);    
}


int main(int argc, char**argv){
    /*variables used*/	
    int status, sockfd, bindfd, recfd, sendfd, clientlen;
    struct addrinfo hints;
    struct addrinfo *servinfo;
    struct sockaddr_in *clientaddr;
    DIR *d;
    struct dirent *dir;
    char buf[BUFSIZE];
    char input[256];
    char ls[BUFSIZE];
    int check = 0;
    char filenames[BUFSIZE];
    long numbytes;
    char* filename;
    char* command;
    FILE *filePtr;
    FILE *fp;
    char* filetype;

    /*checking if port number was input*/
    if(argc != 2){
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    /*filling out addrinfo struct*/
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;
    
    /*getaddrinfo function*/
    status = getaddrinfo(NULL, argv[1], &hints, &servinfo);
    if(status != 0){
        error("Error on getaddrinfo");
    }
    
    /*creating socket*/
    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if(sockfd<0){
        error("error opening socket");
    }
    /* binding */
    bindfd =bind(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);
    if(bindfd<0){
        error("error on bind");
    }
    
    /*used later for recvfrom */
    clientlen = sizeof(clientaddr);


    //main service loop
    while(1){
        
	/*clear memory of buffer and another variable used to decide which command was issued */
        bzero(buf, sizeof(buf));
        bzero(input, 2);

	/*receive clientside message */
        recfd = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &clientaddr, &clientlen);        
        if(recfd<0){
            error("error receiving");
        }

        strncpy(input, buf, 1); //determine which command was input by first char in buf
        

	if(strcmp(input, "g") == 0){//get sequence
                
		/* get sequence breaks up the user input, then opens file, reads data, and sends data over link */
                filename = strtok(buf, " ");
                filename = strtok(NULL, " ");

                filename[strcspn(filename, "\n")] = 0;
			
                filetype = strtok(filename, ".");
               	filetype = strtok(NULL, ".");

               	filetype[strcspn(filetype, "\n")] = 0;

		/* this function formats my string for use in fopen() */
               	snprintf(filenames, sizeof(filenames), "%s.%s", filename, filetype);

		 /*binary file sequence */
      	         if(strcmp(filetype, "bin") == 0){

			filePtr = fopen(filenames,"rb");//read binary option
			
			if(filePtr){
                                fseek(filePtr, 0L, SEEK_END);

                                numbytes = ftell(filePtr);

                                fseek(filePtr, 0L, SEEK_SET);

				fread(buf, BUFSIZE, numbytes, filePtr);
				
				fclose(filePtr);

				sendfd = sendto(sockfd, buf, sizeof(buf) , 0, (struct sockaddr *) &clientaddr, clientlen);

                                if(sendfd<0){
                                        error("error on sendto");
                                }


			}else{

				char err[] = "error opening file";

                                sendfd = sendto(sockfd, err, sizeof(err) , 0, (struct sockaddr *) &clientaddr, clientlen);

                                if(sendfd<0){
                                         error("error on sendto");
                                 }

			}

		}else{//all other filetypes sequence
		
			if((filePtr = fopen((filenames), "r")) == NULL){//open up the file
				char err[] = "error opening file";

		                sendfd = sendto(sockfd, err, sizeof(err) , 0, (struct sockaddr *) &clientaddr, clientlen);
                		
				if(sendfd<0){
                   			 error("error on sendto");
               			 }

			}else{
				/*read and send file sequence*/
				fseek(filePtr, 0L, SEEK_END);
				
				numbytes = ftell(filePtr);
				
				fseek(filePtr, 0L, SEEK_SET);
				
				fread(buf, sizeof(char), numbytes, filePtr);
				
				fclose(filePtr);
		                
				sendfd = sendto(sockfd, buf, sizeof(buf) , 0, (struct sockaddr *) &clientaddr, clientlen);
                		
				if(sendfd<0){
                   			error("error on sendto");
                		}

			}
        
		}
	}else if(strcmp(input, "p") == 0){//put sequence
		
		/*put will format the input, then open new file and insert contents, and finally report status back to the client*/
       	        filename = strtok(buf, " ");
                
		filename = strtok(NULL, " ");

                filename[strcspn(filename, "\n")] = 0;

                filetype = strtok(filename, ".");
                filetype = strtok(NULL, ".");

                filetype[strcspn(filetype, "\n")] = 0;

		/*format string*/
                snprintf(filenames, sizeof(filenames), "%s.%s", filename, filetype);
	    	    
	    	/*  receive the file data */
		recfd = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &clientaddr, &clientlen);
        	if(recfd<0){
            		error("error receiving");
        	}
		

		/*open file*/
		fp = fopen(filenames, "w");

                if(fp == NULL){

                        char err[] = "error opening new file on server side";
			sendfd = sendto(sockfd, err, sizeof(err) , 0, (struct sockaddr *) &clientaddr, clientlen);
                	if(sendfd<0){
                    		error("error on sendto");
                	}

                }else{
			/*insert buf into new file*/
                        int fput = fputs(buf, fp);

                        if(fput>0){

                                printf("success inserting buf into new file\n");
				char suc[] = "success putting file on server side";
				sendfd = sendto(sockfd, suc, sizeof(suc) , 0, (struct sockaddr *) &clientaddr, clientlen);
                		if(sendfd<0){
                    			error("error on sendto");
                		}

                        }else{

                                char err[] = "failure opening file on server side thus the file was not put in the server directory";
                        	sendfd = sendto(sockfd, err, sizeof(err) , 0, (struct sockaddr *) &clientaddr, clientlen);
                        	if(sendfd<0){
                                	error("error on sendto");
                        	}

                        }

                }

                fclose(fp);

        }else if(strcmp(input, "l") == 0){//ls sequence
            
            /*clear memory of vars */
            bzero(ls, sizeof(ls)); 
            bzero(buf, sizeof(buf));
            
	    /*found this sequence from a post on stack overflow about finding all files in the CWD 
             *https://stackoverflow.com/questions/4204666/how-to-list-files-in-a-directory-in-a-c-program
	     */

            d = opendir("."); //returns pointer to the CWD stream
            if(d){
		/* read in file names until no more names left */
                while((dir = readdir(d)) != NULL){
                    if(dir->d_type == DT_REG){
          
                        strcat(ls, dir->d_name);
          
	  		strcat(ls, ", ");
          
	  	    }
                }
                closedir(d);
  
  
  		sendfd = sendto(sockfd,ls,sizeof(ls) , 0, (struct sockaddr *) &clientaddr, clientlen);
                if(sendfd<0){
                    error("error on sendto");
  
  		}else{
  
     		    printf("CWD sent");
      
      		}

            }else{

                char err[] = "error opening the CWD";
                
		sendfd = sendto(sockfd, err, sizeof(err) , 0, (struct sockaddr *) &clientaddr, clientlen);
                
		if(sendfd<0){
                
		    	error("error on sendto");
                
		}
            }

        }else if(strcmp(input, "d") == 0){//delete sequence
          
		/* delete formats the user input then  finds the file and deletes if it exists, and reports to client status */
		filename = strtok(buf, " ");
	
		filename = strtok(NULL, " ");
	
		filename[strcspn(filename, "\n")] = 0; //remove trailing newline char

		/* using remove() to delete files */
		if(remove(("%s",filename)) == 0){
			
			char good[] = "file successfully deleted";
			
			printf("%s was successfully deleted \n", filename);

			sendfd = sendto(sockfd, good, sizeof(good) , 0, (struct sockaddr *) &clientaddr, clientlen);
                	
			if(sendfd<0){
                    		error("error on sendto");
                	}

		}else{
			
			char bad[] = "unable to delete file";
			
			sendfd = sendto(sockfd, bad, sizeof(bad) , 0, (struct sockaddr *) &clientaddr, clientlen);
                	
			if(sendfd<0){
                    		error("error on sendto");
                	}

		}

        }else if(strcmp(input, "e") == 0){ //exit sequence
          
	    /* this just says bye bye my guy */
            char str[] = "goodbye client";
            
            sendfd = sendto(sockfd, str, sizeof(str) , 0, (struct sockaddr *) &clientaddr, clientlen);
            if(sendfd<0){
                error("error on sendto");
            }

        }else{
            
	    /* invalid command sequence just tells the client the message was not understood*/
            char invalid[] = "command not understood please try again";
            sendfd = sendto(sockfd, invalid, sizeof(invalid), 0, (struct sockaddr *) &clientaddr, clientlen);
            if(sendfd<0){
                error("error on sendto");
            }

        }

    }//end of service loop

    return 0;
}
