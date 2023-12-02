#
# Makefile for Project 2
# David J Tinley
# 11/30/2023
#

CC = gcc
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
