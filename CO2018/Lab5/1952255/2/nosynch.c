#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3
#define TCOUNT 100
#define COUNT_LIMIT 20

int count = 10;

void *inc_count(void *tid)
{
  int i;
  long my_id = *(long *)tid;
  for (i = 0; i < TCOUNT; i++)
  {
    count++;
    if (count == COUNT_LIMIT)
    {
      printf("inc_count(): thread %ld, count = %d, threshold reached.\n", my_id, count);
      printf("Just sent signal\n");
    }

    printf("inc_count(): thread %ld, count = %d, unlocking mutex\n", my_id, count);
    sleep(1);
  }

  pthread_exit(NULL);
}

void *watch_count(void *tid)
{
  long my_id = *(long *)tid;
  printf("Starting watch_count(): thread %ld\n", my_id);

  while (count < COUNT_LIMIT)
  {
    printf("watch_count(): thread %ld, count = %d, waiting...\n", my_id, count);
    printf("watch_count(): thread %ld. Condition signal received. Count = %d\n", my_id, count);
    printf("watch_count(): thread %ld. Updating the count value...\n", my_id);
    count += 80;
    printf("watch_count(): thread %ld count now = %d\n", my_id, count);
  }
  printf("watch_count(): thread %ld. Unlocking mutex.\n", my_id);
  pthread_exit(NULL);
}

int main(int argc, char **argv)
{
  int i, rc;
  pthread_t p1, p2, p3;
  long t1 = 1, t2 = 2, t3 = 3;
  pthread_attr_t attr;

  printf("main: begin\n");

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  pthread_create(&p1, &attr, watch_count, (void *)&t1);
  pthread_create(&p2, &attr, inc_count, (void *)&t2);
  pthread_create(&p3, &attr, inc_count, (void *)&t3);

  rc = pthread_join(p1, NULL);
  assert(rc == 0);
  rc = pthread_join(p2, NULL);
  assert(rc == 0);
  rc = pthread_join(p3, NULL);
  assert(rc == 0);

  printf("main: finish, final count = %d\n", count);
  pthread_attr_destroy(&attr);
  pthread_exit(NULL);

  return 0;
}
