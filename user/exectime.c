#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int startTime, endTime;
    int pid;

    if (argc < 2) {
        exit(0);
    }

    startTime = uptime();
    printf("uptime: %d \n", startTime); 

    pid = fork();
    if (pid < 0) {
        exit(0);
    }
    if (pid == 0) {
        exec(argv[1], &argv[1]);
        exit(0);
    }
    wait(0);

    endTime = uptime();   
    printf("uptime: %d\n", endTime);

    exit(0);
}
