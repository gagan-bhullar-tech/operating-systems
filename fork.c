#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("hello: (pid: %d)\n", getpid());

    int rc = fork();
    if (rc < 0) {
        printf("fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child process: %d\n", getpid());
    } else {
        wait(NULL);
        printf("parent: %d\n", getpid());
    }
    exit(0);
}
