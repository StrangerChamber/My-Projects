#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>


#define BUFSIZE 512

int main(int argc, char *argv[]) {
  struct stat buf;
  char cmd[BUFSIZE];
  FILE *f = NULL;

  if (argv[1] == NULL) {
    fprintf(stderr, "Please provide an argument\n");
    exit(1);
  }
  
  if (stat(argv[1], &buf)) {
    fprintf(stderr, "Can't stat the file\n");
    exit(1);
  }
    
  if (buf.st_gid != getegid()) {
    fprintf(stderr, "The file must be owned by group %d\n", getegid());
    exit(1);
  }
  
  if ((f = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Cannot open command file\n");
    return 1;
  }  

  while (fgets(cmd, BUFSIZE, f)) {
    int i;

    for (i=0; cmd[i] != 0; i++) {
        if (!isprint(cmd[i]) && !isspace(cmd[i])) {
	  fprintf(stderr, "Bad characters found.\n");
	  return 1;
        }
    }

    if (system(cmd)) {
      fprintf(stderr, "Command execution error.\n");
      return 1;
    }  
  }
  
  printf("Done!\n");
  return 0;
}
