#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();

    if (rc == 0) {
        char *args[] = {"ls", "mem.c", NULL};
        execv("/bin/ls", args);
    } else {
        wait(NULL);
    }
}
