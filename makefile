CC = g++
CFLAGS  = -g -Wall
default: program2

program2: program2.o
	$(CC) $(CFLAGS) -o program2 program2.o -lm

program2.o: program2.c
	$(CC) $(CFLAGS) -c program2.c

clean:
	$(RM) program2 *.o *~
