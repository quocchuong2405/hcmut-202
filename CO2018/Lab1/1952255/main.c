#include "factorial.h"
#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv)
{
  char input[64];

  while (1)
  {
    printf("Input yo number right below here\n");

    if (read_line(input) == 0)
    {
      if (strncmp(input, "exit", 4) == 0)
      {
        printf("Exiting...\n");
        break;
      }
      else
        printf("This ain't a number. I mean\n-1\n");
    }
    else
      printf("Yo result is %d.\n", factorial(atoi(input)));
  }

  return 0;
}
