OBJS = main.o protocal.o wrap.o
COMMON = ../common/
CC = gcc
CFLAGS = -Wall -g -O2
LDFLAGS = -lconfig

carserver: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o carserver

main.o: main.c $(COMMON)protocal.h $(COMMON)eCorner.h wrap.h 
	$(CC) $(CFLAGS) -c main.c

protocal.o: $(COMMON)protocal.c $(COMMON)protocal.h
	$(CC) $(CFLAGS) -c $(COMMON)protocal.c

wrap.o: wrap.c
	$(CC) $(CFLAGS) -c wrap.c

clean:
	rm -rf *.o carserver

