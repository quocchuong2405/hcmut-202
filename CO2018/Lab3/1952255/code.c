#include <stdio.h>
#include <pthread.h>

void *hello(void *tid)
{
  printf("Hello from thread %d\n", *(int *)tid);
  return NULL;
}

int main()
{
  pthread_t tid[10];
  int i = 0;

  for (i = 0; i < 10; i++)
  {
    if (pthread_create(&tid[i], NULL, hello, (void *)&i) != 0)
      return -1;
    pthread_join(tid[i], NULL);
  }

  pthread_exit(NULL);

  return 0;
}
