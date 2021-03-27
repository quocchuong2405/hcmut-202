#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  pid_t pidA, pidB, pidC, pidD, pidE, pidF, pidG, pidI;

  pidA = fork();
  if (pidA < 0)
  {
    perror("A");
    exit(1);
  }
  else if (pidA == 0)
  {
    printf("%d: A\n", getpid());

    pidB = fork();
    if (pidB < 0)
    {
      perror("B");
      exit(1);
    }
    else if (pidB == 0)
    {
      printf("%d: B\n", getpid());

      pidE = fork();
      if (pidE < 0)
      {
        perror("E");
        exit(1);
      }
      else if (pidE == 0)
      {
        printf("%d: E\n", getpid());

        pidI = fork();
        if (pidI < 0)
        {
          perror("I");
          exit(1);
        }
        else if (pidI == 0)
        {
          printf("%d: I\n", getpid());
        }
        else
        {
          ;
        }
      }
      else
      {
        pidF = fork();
        if (pidF < 0)
        {
          perror("F");
          exit(1);
        }
        else if (pidF == 0)
        {
          printf("%d: F\n", getpid());
        }
        else
        {
          ;
        }
      }
    }
    else
    {
      pidC = fork();
      if (pidC < 0)
      {
        perror("C");
        exit(1);
      }
      else if (pidC == 0)
      {
        printf("%d: C\n", getpid());

        pidG = fork();
        if (pidG < 0)
        {
          perror("G");
          exit(1);
        }
        else if (pidG == 0)
        {
          printf("%d: G\n", getpid());
        }
        else
        {
          ;
        }
      }
      else
      {
        pidD = fork();
        if (pidD < 0)
        {
          perror("D");
          exit(1);
        }
        else if (pidD == 0)
        {
          printf("%d: D\n", getpid());
        }
        else
        {
          ;
        }
      }
    }
  }
  else
  {
    ;
  }

  return 0;
}