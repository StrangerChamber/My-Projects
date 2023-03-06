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

#define CHUNK_SIZE 65536
#define DEBUG  


int main()
{
  int index = 0;
  char buffer[CHUNK_SIZE];
  int ret = 0;

  printf("Ready to read!\n");
  fflush(stdout);
  index = 0;
  gets(buffer);
  while ((ret = getchar()) > 0) {
    buffer[index] = ret;
    index++;
    buffer[index] = '\0';
    fflush(stdout);
    if (buffer[index - 1] == 0x0a) {
      buffer[index - 1] = '\0';
      break;
    }
  }
  if (ret < 0) {
    fprintf(stderr, "ERROR: read failed: %s\n", strerror(errno));
    return 1;
  }

  printf("Received: %s\n", buffer);
  printf("Done!\n");
  fflush(stdout);
  return 0;
}