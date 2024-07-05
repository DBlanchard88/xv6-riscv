#include "types.h"
#include "stat.h"
#include "user.h"

#define ITERATIONS 1000000000000000  

int main(int argc, char *argv[]) {
    double pi = 0.0;
    int i;

    for (i = 0; i < ITERATIONS; i++) {
        pi += (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
    }
    pi *= 4.0;

    exit(0);
}