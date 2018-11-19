IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CFLAGS+=-DLINUX
endif

Step1_KL: step1_KL.cpp Graph.cpp Partition.cpp
	make clean
	$(CC) -o step1_KL.o step1_KL.cpp Graph.cpp Partition.cpp $(CFLAGS)
  
.PHONY: clean

clean:
	rm -f step1_KL.o
