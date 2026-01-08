#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("start: %d\n", getpid());

    int x = 1;

    int rc = fork();

    if (rc < 0) {
        printf("fork fail");
    } else if (rc == 0) {
        x = 9;
        printf("child process: %d value: %d\n", getpid(), x);
    } else {
        x = 90;
        wait(NULL);
        printf("parent process id: %d value: %d\n", getpid(), x);
    }
}
