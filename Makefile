# note: must use CPPFLAGS for -g to work with c++ compiler
CC=g++
CPPFLAGS=-c -Wall -g
BINS= calc

all: calc test

calc: main.o calc.o
	$(CC) -o calc main.o calc.o

test: testing.o calc.o
	$(CC) -o test testing.o calc.o

clean:
	rm -rf *o *~ $(BINS)
