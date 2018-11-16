# Kernighan-Lin_PartitioningSoftware #

Kernighan-Lin heuristic algorithm for finding partitions of graphs implented in C++.

The algorithm has important applications in the layout of digital circuits and components in VLSI.

[Kernighan-Lin Algorithm Wiki](https://en.wikipedia.org/wiki/Kernighan%E2%80%93Lin_algorithm)

The algorithm starts with a random partition of equal sized vertices. For example (1, ..., n) 
vertices in partition #1 and (1+n, ..., 2n) vertices in partition #2.

The project will be completed in 3 steps:

### Step 1(step1_KL.cpp): Format of the Input & Output ###

Program will read an input file and print out a partition in a specified format

  - [ ] **A.** Each input file contains 2n vertices.
  
  - [ ] **B.** As the starting partition, assign (1, ..., n) vertices in partition #1 & (n+1, ..., 2n)
  vertices in partition #2.

### Step 2(step2_KL.cpp): Expand step 1 to include the following ###

  - [ ] **A.** Calculate the cost of a partition.
  
  - [ ] **B.** Update your output formate to show "cost of the partition".

### Step 3(step3_KL.cpp & KL.cpp): Expand step 2 to include the following ###

  - [ ] **A.** Calculate the internal & external costs for all of the vertices in both partitions.
  
  - [ ] **B.** Calculate the D values for each node
  
  - [ ] **C.** Calculate the Gain values for each possible "move".
  
  - [ ] **D.** In addition to the cost of the partition, print the largest Gain value.
