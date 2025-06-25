# CSDS 202 – Data Structures Projects (2020)

This repository includes three major C++ projects developed by **İlke Kaş (21803184)** for **CSDS 201 – Data Structures, Section 3** at Bilkent University in 2020. Each folder showcases the implementation of core data structures and algorithmic concepts through practical, performance-driven applications.

---

## 📁 Repository Structure

### 📂 Folder 1: Binary Search Tree

**Topic:** Tree Data Structures  
**Key Data Structures:**  
- Binary Node (with parent-child pointers)  
- Binary Search Tree (recursive traversal and operations)

**Features:**
- Insert, remove, and search for values
- Preorder, inorder, postorder, and level-order traversals
- Compute height and number of nodes
- Mirror tree (swap all children)
- Count nodes within a range (`span(a, b)`)

**Files:**
- `BinaryNode.h / .cpp`
- `BinarySearchTree.h / .cpp`
- `Makefile`

---

### 📂 Folder 2: Print Request Scheduler (Heap-Based)

**Topic:** Priority Queues & Simulation  
**Key Data Structures:**
- Max Binary Heap  
- Priority Queue  
- Dynamic Arrays for job queues  
- Simulation engine (`Simulator`)

**Features:**
- Parses input log of print jobs with request time, process time, and priority
- Simulates printer assignment over time
- Uses heap-based priority queue to schedule jobs
- Determines the **minimum number of printers** needed to keep the **average waiting time** below a given threshold
- Tracks total waiting time and request status

**Files:**
- `main.cpp`
- `PrintRequest.h / .cpp`
- `Printer.h / .cpp`
- `Heap.h / .cpp`
- `PriorityQueue.h / .cpp`
- `simulator.h / .cpp`
- `Makefile`

---

### 📂 Folder 3: Sorting Algorithms and Performance Analysis

**Topic:** Algorithm Efficiency  
**Key Data Structures:**
- Raw Arrays  
- Auxiliary arrays for merge and radix sort

**Implemented Algorithms:**
- Selection Sort (O(n²))
- Merge Sort (O(n log n), stable)
- Quick Sort (O(n log n) average, O(n²) worst)
- Radix Sort (O(k·n) for digit-based keys)

**Features:**
- Benchmarks each algorithm with:
  - Random arrays
  - Ascending arrays
  - Descending arrays
- Tracks:
  - Elapsed time (ms)
  - Number of key comparisons
  - Number of data moves
- Includes a detailed performance report with graphs and analysis

**Files:**
- `main.cpp`
- `sorting.h / .cpp`
- `Makefile`
- `hw1.pdf` (full report)
- `Description` (overview)

---

## 📑 Summary of Concepts Covered

| Project                 | Key Focus                            | Core Concepts                      |
|-------------------------|--------------------------------------|------------------------------------|
| Binary Search Tree      | Recursive tree operations            | BSTs, traversal, memory management |
| Print Request Simulator | Priority-based scheduling simulation | Heaps, priority queues, simulation |
| Sorting Performance     | Theoretical vs. empirical efficiency | Sorting, benchmarking, analysis    |
