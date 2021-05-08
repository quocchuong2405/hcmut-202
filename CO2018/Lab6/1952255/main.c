#include "mem.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 4

void *proc(void *args)
{
  int i;
  int index = 0;
  char *mem[ARRAY_SIZE];
  for (i = 0; i < ARRAY_SIZE; i++)
  {
    if (rand() % 2)
    {
      /* Allocate memory */
      unsigned int size = 1 << ((rand() % 4) + 4);
      mem[index] = mem_alloc(size, *(int *)args);
      if (mem[index] != NULL)
      {
        index++;
      }
    }
    else
    {
      // Free memory
      if (index == 0)
      {
        continue;
      }
      unsigned char j = rand() % index;
      mem_free(mem[j]);
      mem[j] = mem[index - 1];
      index--;
    }
  }
}

void proc_test()
{
  int i;
  int index = 0;
  char *mem[5];
  int arr_alloc[5] = {115, 500, 358, 200, 375};
  for (i = 0; i < 5; i++)
  {
    /* Allocate memory */
    mem[index] = mem_alloc(arr_alloc[i], 0);
    if (mem[index] != NULL)
    {
      index++;
    }
  }

  index = 0;
  for (i = 0; i < 5; i++)
  {
    /* Allocate memory */
    mem[index] = mem_alloc(arr_alloc[i], 1);
    if (mem[index] != NULL)
    {
      index++;
    }
  }

  index = 0;
  for (i = 0; i < 5; i++)
  {
    /* Allocate memory */
    mem[index] = mem_alloc(arr_alloc[i], 2);
    if (mem[index] != NULL)
    {
      index++;
    }
  }
}

void init_test()
{
  srand(time(NULL));

  mem_init(2325);

  proc_test();

  mem_finish();
}

int main(int argc, char **argv)
{
  int opt = 0;
  if (argc == 2 && argv[1] > 0)
  {
    opt = atoi(argv[1]);
  }

  srand(time(NULL));

  // Allocate 1KB memory
  mem_init(1 << 10);

  pthread_t p_0, p_1;
  pthread_create(&p_0, NULL, proc, (void *)&opt);
  pthread_create(&p_1, NULL, proc, (void *)&opt);
  pthread_join(p_0, NULL);
  pthread_join(p_1, NULL);

  mem_finish();
}
