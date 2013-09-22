CC=gcc

all: 		myfork

myfork:		myfork.o
			${CC} -o myfork myfork.o 

myfork.o:	myfork.c
			${CC} -c myfork.c

clean:
			rm *.o myfork
