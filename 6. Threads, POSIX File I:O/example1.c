#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main(int argc, char **argv) {
  char buffer[BUFFER_SIZE];

  while (1) {
    /* Write the prompt to standard out. */
    printf("Enter a sentence or press Ctrl-D to quit:\n");

    /* Read a line from standard input */
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
      break;  // Exit loop if fgets returns NULL
    }

    /* Echo the line back to standard output */
    printf("You entered the sentence: %s", buffer);
  }

  return 0;
}
