all: serial multi-thread sync-async

serial: pi_serial.c
	clang pi_serial.c -o problem_1.1.

multi-thread: pi_multi-thread.c
	clang pi_multi-thread.c -o problem_1.2. -pthread

sync-async: code.c
	clang code.c -o problem_2. -pthread

clean:
	rm problem_1.1. problem_1.2. problem_2.
