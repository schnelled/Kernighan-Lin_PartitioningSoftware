IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CFLAGS+=-DLINUX
endif

Step2_KL: Step2_KL.cpp Graph.cpp Partition.cpp Node.cpp
	make clean
	$(CC) -o Step2_KL.o Step2_KL.cpp Graph.cpp Partition.cpp Node.cpp $(CFLAGS)
	
.PHONY: clean

clean:
	rm -f Step2_KL.o
