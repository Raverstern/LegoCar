OBJS = main.o protocal.o wrap.o
CC = gcc
CFLAGS = -Wall -g -O2
LDFLAGS = -lconfig

carserver: $(OBJS);
	$(CC) $(OBJS) $(LDFLAGS) -o carserver

main.o: main.c protocal.h wrap.h
	$(CC) $(CFLAGS) -c main.c

protocal.o: protocal.c protocal.h
	$(CC) $(CFLAGS) -c protocal.c

wrap.o: wrap.c wrap.h
	$(CC) $(CFLAGS) -c wrap.c

clean:
	rm -rf *.o carserver

