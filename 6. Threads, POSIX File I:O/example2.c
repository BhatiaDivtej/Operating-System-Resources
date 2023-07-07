#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s file1 [file2 ...]\n", argv[0]);
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "Error opening file: %s\n", argv[i]);
      continue;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
      putchar(c);
    }

    if (fclose(fp) == EOF) {
      fprintf(stderr, "Error closing file: %s\n", argv[i]);
      exit(1);
    }
  }

  return 0;
}
