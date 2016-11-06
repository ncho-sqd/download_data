CC = gcc
CFLAGS1 = -Wall
CFLAGS2 = -o
CFLAGS3 = -c

OBJS1 = bar.o foo.o
OBJS2 = bar.c
OBJS3 = foo.c

main: $(OBJS1)
	$(CC) $(CFLAGS1) $^ $(CFLAGS2) main

bar.o: bar.c bar.h
	gcc -Wall -c bar.c -o $@

foo.o: foo.c foo.h bar.h
	gcc -Wall -c foo.c -o $@

clean:
	rm -f foo.o bar.o main


