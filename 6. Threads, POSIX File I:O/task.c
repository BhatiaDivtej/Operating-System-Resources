/* TODO: Implement the Programming task here. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  int pipefd[2];
  int fdin, fdout;

  // Create a pipe
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  // Fork a child process
  pid_t pid = fork();

  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    // Child process

    // Close the read end of the pipe
    close(pipefd[0]);

    // Redirect stdout to the write end of the pipe
    if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
      perror("dup2");
      exit(EXIT_FAILURE);
    }

    // Close the write end of the pipe
    close(pipefd[1]);

    // Open the input file and redirect stdin to it
    fdin = open("many_words.txt", O_RDONLY);

    if (fdin == -1) {
      perror("open");
      exit(EXIT_FAILURE);
    }

    if (dup2(fdin, STDIN_FILENO) == -1) {
      perror("dup2");
      exit(EXIT_FAILURE);
    }

    // Execute the "sort" command
    execlp("sort", "sort", NULL);

    perror("exec");
    exit(EXIT_FAILURE);
  } else {
    // Parent process

    // Close the write end of the pipe
    close(pipefd[1]);

    // Redirect stdin to the read end of the pipe
    if (dup2(pipefd[0], STDIN_FILENO) == -1) {
      perror("dup2");
      exit(EXIT_FAILURE);
    }

    // Close the read end of the pipe
    close(pipefd[0]);

    // Open the output file and redirect stdout to it
    fdout = open("sorted_tail.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fdout == -1) {
      perror("open");
      exit(EXIT_FAILURE);
    }

    if (dup2(fdout, STDOUT_FILENO) == -1) {
      perror("dup2");
      exit(EXIT_FAILURE);
    }

    // Execute the "tail" command
    execlp("tail", "tail", NULL);

    perror("exec");
    exit(EXIT_FAILURE);
  }

  return 0;
}
