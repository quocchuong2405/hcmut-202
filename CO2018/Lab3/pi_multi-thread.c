#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include <time.h>

void *runner(void *param);

struct Arguments
{
  int argv1;
  int argv2;
}; // struct Arguments

int main(int argc, char **argv)
{
  int circle = 0, total = 0, numThreads = 2;

  if (argc == 2 && argv[1] > 0)
  {
    total = atoi(argv[1]);
  }
  else if (argc == 3 && argv[1] > 0 && argv[2] > 0)
  {
    total = atoi(argv[1]);
    numThreads = atoi(argv[2]);
  }
  else
    return -1;

  clock_t start = clock();

  struct Arguments args;
  args.argv1 = circle;
  args.argv2 = total / numThreads;

  pthread_t pid[numThreads];
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  for (int i = 0; i < numThreads; i++)
  {
    if (pthread_create(&pid[i], &attr, runner, (void *)&args) != 0)
      return -1;
    pthread_join(pid[i], NULL);
  }

  circle = args.argv1;
  double result = 4.0 * circle / total;

  clock_t end = clock();
  double elapsed = 1.0 * (end - start) / CLOCKS_PER_SEC;

  printf("Pi = %lf\n", result);
  printf("Time taken = %lf seconds\n", elapsed);
  return 0;
}

void *runner(void *argv)
{
  struct Arguments *args = (struct Arguments *)argv;
  int total = args->argv2;

  for (int i = 0; i++ < total;)
  {
    double x = 1.0 * rand() / RAND_MAX;
    double y = 1.0 * rand() / RAND_MAX;

    if (x * x + y * y <= 1)
      args->argv1 += 1;
  }

  pthread_exit(NULL);
}
