all: serial multi-thread sync-async

serial: pi_serial.c
	gcc pi_serial.c -o problem_1.1.

multi-thread: pi_multi-thread.c
	gcc pi_multi-thread.c -o problem_1.2. -lpthread

sync-async: code.c
	gcc code.c -o problem_2. -lpthread

clean:
	rm problem_1.1. problem_1.2. problem_2.
