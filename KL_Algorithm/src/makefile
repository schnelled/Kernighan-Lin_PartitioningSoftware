IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CFLAGS+=-DLINUX
endif

Step3_KL: KL_Algorithm.cpp Graph.cpp Partition.cpp Node.cpp
	make clean
	$(CC) -o KL_Algorithm.o KL_Algorithm.cpp Graph.cpp Partition.cpp Node.cpp $(CFLAGS)
	
.PHONY: clean

clean:
	rm -f KL_Algorithm.o
