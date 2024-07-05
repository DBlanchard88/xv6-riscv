
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(int argc, char *argv[]) {
  int fd;
  char buf[512];
  int n;

  fd = open("sh_history", O_RDONLY);
  if(fd < 0) {
    printf("can not open sh_history\n");
    exit(1);
  }
  
  while((n = read(fd, buf, sizeof(buf))) > 0) {
    write(1, buf, n);
  }

  if(n < 0) {
    printf("history read error\n");
    exit(1);
  }

  close(fd);
  exit(1);
}