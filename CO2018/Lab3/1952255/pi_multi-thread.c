#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include <time.h>

// *This is bad practice
unsigned int inCircle = 0, total = 0, perThread = 0, numThreads = 2;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *runner(void *param)
{
  // * random() considerably slows this down
  unsigned int rand_state = rand();
  unsigned int inThread = 0;

  for (unsigned int i = 0; i++ < perThread;)
  {
    double x = 1.0 * rand_r(&rand_state) / RAND_MAX;
    double y = 1.0 * rand_r(&rand_state) / RAND_MAX;

    if (x * x + y * y <= 1)
      inThread += 1;
  }

  // * Mutex lock
  pthread_mutex_lock(&mutex);
  inCircle += inThread;
  pthread_mutex_unlock(&mutex);

  pthread_exit(NULL);
  return NULL;
}

int main(int argc, char **argv)
{
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

  pthread_t pid[numThreads];
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  perThread = 1 + total / numThreads; // * Not guaranteed

  for (unsigned int i = 0; i < numThreads; i++)
    if (pthread_create(&pid[i], &attr, runner, NULL) != 0)
      return -1;

  for (unsigned int i = 0; i < numThreads; i++)
    pthread_join(pid[i], NULL);

  double result = 4.0 * inCircle / total;

  clock_t end = clock();
  double elapsed = 1.0 * (end - start) / CLOCKS_PER_SEC / numThreads;

  printf("Pi = %lf\n", result);
  printf("Time taken = %lf seconds\n", elapsed);
  return 0;
}
