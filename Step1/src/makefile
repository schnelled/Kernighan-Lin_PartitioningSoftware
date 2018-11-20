IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CFLAGS+=-DLINUX
endif

Step1_KL: Step1_KL.cpp Graph.cpp Partition.cpp Node.cpp
	make clean
	$(CC) -o Step1_KL.o Step1_KL.cpp Graph.cpp Partition.cpp Node.cpp $(CFLAGS)
  
.PHONY: clean

clean:
	rm -f step1_KL.o
