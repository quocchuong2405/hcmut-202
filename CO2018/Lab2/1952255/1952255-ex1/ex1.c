#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  // * Prerequisite
  const char *PATH = "numbers.txt";
  const int MAX_LINE_LENGTH = 64;
  const int MAX_LINE = 128;

  // *
  char line[MAX_LINE_LENGTH];
  int data[MAX_LINE];
  unsigned int line_count = 0;

  for (int i = 0; i++ < MAX_LINE_LENGTH;)
    line[i] = '\0';
  for (int i = 0; i++ < MAX_LINE;)
    data[i] = -1;

  // * Open as read only
  FILE *file = fopen(PATH, "r");
  // * Not found
  if (!file)
  {
    perror(PATH);
    return EXIT_FAILURE;
  }

  // * Reader
  while (fgets(line, 64, file))
  {
    data[line_count] = atoi(line);
    line_count += 1;
  }

  // * Main
  int pid = fork();
  if (pid > 0) // Parent
  {
    int result = 0;
    for (int i = 0; i < MAX_LINE; i += 1)
      if (data[i] % 2 == 0 && data[i] >= 0)
        result += 1;

    printf("Parent: %d\n", result);
    wait(NULL);
  }
  else if (pid == 0) // Child
  {
    int result = 0;
    for (int i = 0; i < MAX_LINE; i += 1)
      if (data[i] % 3 == 0 && data[i] >= 0)
        result += 1;

    printf("Child: %d\n", result);
  }
  else // Error
  {
    ;
  }

  // * Close file
  if (fclose(file))
  {
    return EXIT_FAILURE;
    perror(PATH);
  }

  return 0;
}