#$(CC) -c $(CFLAGS) $(CPPFLAGS) $(SRC)

CC = gcc
SRC = ./operationsBST.c ./main.c
INCLUDE = ./
TGT = main.out

CFLAGS = -g -Wall -Werror
CPPFLAGS = -I $(INCLUDE)

OBJS = $(SRC:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) $(CPPFLAGs) -c $^ -o $@

.PHONY:compile-all
compile-all:$(OBJS)

.PHONY:build
build:compile-all
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) -o $(TGT)

.PHONY:clean
clean:
	rm -f main.o operationsBST.o main.out
