#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <pwd.h>
#include <sys/errno.h>
#include <netdb.h>



int main(){
    int index = 0;
  char buffer[10];
  int ret = 0;
  while((ret = read(0, &buffer[index],1)) > 0){
    printf("%c", buffer[index]);
    index++;
    buffer[index] = '\0';
    fflush(stdout);
    if (buffer[index - 1] == 0x0a) {
      buffer[index - 1] = '\0';
      break;
    }
  }
  return 0;
}