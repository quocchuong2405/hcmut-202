# Lab 3

## Problem 1: Monte *fucking* Carlo

### How to build this thing

```Makefile
make all
```

Or `make` to run the first option if you are lazy

### How to run this thing

The serial program takes one argument as the number of samples

```bash
./problem_1.1. <samples>
```

The multi-thread program takes two arguments, one for the number of samples, the other for the number of threads, which defaults to 2

```bash
./problem_1.2. <samples> <!threads>
```

You have a problem with this naming scheme? Ask the one who made the instructions.

## Problem 2: Quiz

If we want the threads to print their ID in ascending order, they must not be executed concurrently.
Hence we just need to join each thread after it's been executed.

```C
  pthread_create(&tid[i], NULL, hello, (void *)&i);
  pthread_join(tid[i], NULL);
```
