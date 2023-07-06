// Take a look at some of the previous examples to create your own program!
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>  // Includes some new data types (e.g. pid_t)


int main() {
    pid_t pid1;
    pid_t pid2;
    pid_t pid3;

    // Execute "ps -uf" using execve
    pid1 = fork();
    if (pid1 == 0) {
        char *args[] = {"ps", "-uf", NULL};
        execve("/bin/ps", args, NULL);
    }

    // Wait for ps command to complete before continuing
    waitpid(pid1, NULL, 0);

    // Execute "echo --help" using execve
    pid2 = fork();
    if (pid2 == 0) {
        char *args[] = {"echo", "--help", NULL};
        execve("/bin/echo", args, NULL);
    }

    // Wait for echo command to complete before continuing
    waitpid(pid2, NULL, 0);

    // Execute "nl -b a example1.c" using execve
    pid3 = fork();
    if (pid3 == 0) {
        char *args[] = {"nl", "-b", "a", "example1.c", NULL};
        execve("/usr/bin/nl", args, NULL);
    }

    // Wait for nl command to complete before continuing
    waitpid(pid3, NULL, 0);

    // Execute example5.c program
    pid_t pid4 = fork();
    if (pid4 == 0) {
        char *args[] = {"./example5", NULL};
        execve("./example5", args, NULL);
    }

    // Wait for example5.c program to complete before exiting
    waitpid(pid4, NULL, 0);

    return 0;
}
