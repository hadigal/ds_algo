CC = gcc
CFLAGS = -g -Wall -Werror
CPPFLAGS = -I ./

SRC_LIST = ./listLib.c ./mainList.c
TARGET_LIST = build.out

SRC_STACK = ./stackLib.c ./stackArrMain.c
STACK_TGT = stackArrTgt.out

SRC = ./listLib.c ./mainList.c ./stackLib.c ./stackArrMain.c ./mergeSortLL.c

OBJS = $(SRC:.c=.o)


.PHONY:build-stackarr
build-stackarr:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(SRC_STACK)
	$(CC) $(CFLAGS) stackLib.o stackArrMain.o -o $(STACK_TGT)

.PHONY:build-list
build-list:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) stackLib.c stackArrMain.c
	$(CC) $(CFLAGS) listLib.o mainList.o -o $(STACK_TGT)

.PHONY:build
build:
		$(CC) -c $(CFLAGS) $(CPPFLAGS) $(SRC)
		$(CC) $(CFLAGS) stackLib.o stackArrMain.o -o $(STACK_TGT)
		$(CC) $(CFLAGS) listLib.o mergeSortLL.o mainList.o -o $(TARGET_LIST)

.PHONY:clean
clean:
	rm -f *.o *.out
