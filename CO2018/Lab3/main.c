#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_PTHREAD 5

void *PrintHello(void *threadid)
{
  long tid;
  tid = (long)threadid;
  printf("Hello World! It's me, thread #%ld!\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char **argv)
{
  pthread_t threads[NUM_PTHREAD];
  int rc;
  long t;
  for (t = 0; t < NUM_PTHREAD; t++)
  {
    printf("In main: creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    if (rc)
    {
      printf("ERROR: return from pthread create() is %d\n", rc);
      exit(-1);
    }
  }

  pthread_exit(NULL);
}