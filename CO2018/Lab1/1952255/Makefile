all: main.o factorial.o readline.o
	gcc main.o factorial.o readline.o -o myfactorial

main.o: factorial.h readline.h  main.c
	gcc -c main.c

factorial.o: factorial.h factorial.c
	gcc -c factorial.c

readline.o: readline.h readline.c
	gcc -c readline.c

clean:
	rm -f *.o myfactorial