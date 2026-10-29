CC = gcc
CFLAGS = -Wall -Wextra -std=c99

EXOS = Ex_1.o Ex_2.o Ex_3.o Ex_4.o

all: test_pile test_exos

test_pile: test_pile.o PILE.o
	$(CC) $^ -o $@

test_exos: test_exos.o PILE.o $(EXOS)
	$(CC) $^ -o $@

%.o: %.c PILE.h Booleen.h
	$(CC) $(CFLAGS) -c $< -o $@

test: all
	./test_pile
	./test_exos

clean:
	rm -f *.o test_pile test_exos

.PHONY: all test clean