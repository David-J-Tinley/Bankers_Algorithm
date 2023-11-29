

CC = clang
CFLAGS = -g -Wall -std=c17

message:
	@echo 'Options are:'
	@echo 'main'
	@echo 'clean'

main: main.o
	${CC} ${CFLAGS} main.o -o main

main.o:
	${CC} ${CFLAGS} -c main.c

clean:
	rm -f main
	rm -f *.o
	rm -rf *.dSYM/
