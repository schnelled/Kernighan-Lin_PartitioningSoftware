IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CFLAGS+=-DLINUX
endif

Step3_KL: Step3_KL.cpp Graph.cpp Partition.cpp Node.cpp
	make clean
	$(CC) -o Step3_KL.o Step3_KL.cpp Graph.cpp Partition.cpp Node.cpp $(CFLAGS)
	
.PHONY: clean

clean:
	rm -f Step3_KL.o
