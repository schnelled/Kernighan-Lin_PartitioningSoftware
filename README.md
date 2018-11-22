# Kernighan-Lin_PartitioningSoftware #

Kernighan-Lin heuristic algorithm for finding partitions of graphs implented in C++.

The algorithm has important applications in the layout of digital circuits and components in VLSI.

[Kernighan-Lin Algorithm Wiki](https://en.wikipedia.org/wiki/Kernighan%E2%80%93Lin_algorithm)

The algorithm starts with a random partition of equal sized vertices. For example (1, ..., n) 
vertices in partition #1 and (1+n, ..., 2n) vertices in partition #2.

The project will be completed in 3 steps:

### Step 1(step1_KL.cpp): Format of the Input & Output ###

Program will read an input file and print out a partition in a specified format

  - [x] **A.** Each input file contains 2n vertices.
  
  - [x] **B.** As the starting partition, assign (1, ..., n) vertices in partition #1 & (n+1, ..., 2n)
  vertices in partition #2.

### Step 2(step2_KL.cpp): Expand step 1 to include the following ###

  - [x] **A.** Calculate the cost of a partition.
  
  - [x] **B.** Update your output formate to show "cost of the partition".

### Step 3(step3_KL.cpp & KL_Algorithm.cpp): Expand step 2 to include the following ###

  - [x] **A.** Calculate the internal & external costs for all of the vertices in both partitions.
  
  - [x] **B.** Calculate the D values for each node
  
  - [x] **C.** Calculate the Gain values for each possible "move".
  
  - [x] **D.** In addition to the cost of the partition, print the largest Gain value.
  
### Running Program:

**Step1:** cd KL_Algorithm/src

**Step2:** make

**Step3:** ./KL_Algorithm.o <benchmarkFile.txt>

Example: ./KL_Algorithm.o ../../Benchmark/ClassEx/ClassEx.txt

**Step4 (once finished):** make clean
  
**Note:** As of November 21, 2018 the algorithm is function and tested using the provided benchmarks on Linux Ubuntu 18.04.1 LST and will be tested on more systems in the near future.
