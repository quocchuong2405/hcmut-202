#include <stdlib.h>
#include <stdio.h>

#include <time.h>

int main(int argc, char **argv)
{
  if (argc != 2 || atoi(argv[1]) < 0)
    return -1;

  clock_t start = clock();

  int inCircle = 0, total = atoi(argv[1]);

  for (int i = 0; i++ < total;)
  {
    double x = 1.0 * rand() / RAND_MAX;
    double y = 1.0 * rand() / RAND_MAX;

    if (x * x + y * y <= 1)
      inCircle += 1;
  }

  double result = 4.0 * inCircle / total;

  clock_t end = clock();
  double elapsed = 1.0 * (end - start) / CLOCKS_PER_SEC;

  printf("Pi = %lf\n", result);
  printf("Time taken = %lf seconds\n", elapsed);
  return 0;
}
