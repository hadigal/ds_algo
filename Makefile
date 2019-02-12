CC = gcc
CFLAGS = -g -Wall -Werror
CPPFLAGS = -I ./
SRC = ./listLib.c ./main.c
OBJS = $(SRC:.c=.o)
TARGET = build.out

.PHONY:build
build:
		$(CC) -c $(CFLAGS) $(CPPFLAGS) $(SRC)
		$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

.PHONY:clean
clean:
	rm -f *.o *.out
