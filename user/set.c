#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main (int argc, char *argv[]) {
  int priority, pid;

  pid = atoi(argv[1]);
  priority = atoi(argv[2]);
  if(priority < 0 || priority > 20) {
    printf("Invalid priority value\n");
    exit(0);
  }
  set(pid, priority);
  exit(0);
}