#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int read_line(char *str)
{
  // * This line does nothing
  scanf("%s", str);

  // * Digit checking
  int isInt = 1;
  for (int i = 0; str[i] != '\0'; i += 1)
    if (isdigit(str[i]) == 0)
    {
      isInt = 0;
      break;
    }

  // * Final return
  if (isInt == 1)
    return 1;
  return 0;
}
