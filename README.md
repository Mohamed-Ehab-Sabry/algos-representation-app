# Algos Representation App

![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A command-line application that implements and demonstrates fundamental algorithms for searching, sorting, and calculating Fibonacci numbers. This project was developed in C++ for the "CS321 - Algorithms Analysis and Design" course at Cairo University.

---

## 📋 Table of Contents

* [About The Project](#about-the-project)
* [Features Implemented](#features-implemented)
* [Getting Started](#getting-started)
    * [Prerequisites](#prerequisites)
    * [Compilation & Execution](#compilation--execution)
* [Project Structure](#project-structure)
* [License](#license)
* [Acknowledgments](#acknowledgments)

---

## 📖 About The Project

This repository contains C++ implementations of various core algorithms as required by an assignment for the CS321 course at the Faculty of Computer and Artificial Intelligence, Cairo University. The goal is to provide a hands-on demonstration of different algorithmic techniques and data structures, including their recursive and iterative approaches.

The project is divided into three main parts:
1.  **Fibonacci Series Calculation**
2.  **Searching Algorithms**
3.  **Heap-based Data Structures and Sorting**

---

## ✨ Features Implemented

### 1. Fibonacci Series
Functions to compute the n-th Fibonacci number using three distinct methods:
* **Recursion:** The classic recursive implementation.
* **Divide and Conquer:** An optimized approach using matrix exponentiation.
* **Dynamic Programming:** An efficient bottom-up approach to avoid re-computation.

### 2. Search Algorithms
A collection of search algorithms demonstrating both iterative and recursive solutions.
* **Sequential Search:**
    * Iterative implementation that searches for a target in a list.
    * Recursive implementation of the sequential search algorithm.
* **Binary Search:**
    * Iterative implementation for searching within a sorted list.
    * Recursive implementation that takes low and high indices to search a sub-list.

### 3. Heap, Priority Queue, and Heap Sort
* **Heap Implementation:** A custom max-heap class with core methods:
    * `insert()` to add an element while maintaining the heap property.
    * `heapify()` to enforce the heap property.
    * `extractMax()` to remove and return the largest element.
* **Priority Queue:** A priority queue implemented using the custom heap structure, with methods for insertion and extraction of the highest priority element.
* **Heap Sort:** An efficient, in-place sorting algorithm that utilizes the heap implementation to sort an array.

---

## 🚀 Getting Started

To get a local copy up and running, follow these simple steps.

### Prerequisites

You need a C++ compiler installed on your system. The `g++` compiler is recommended.
* **To check if you have g++:**
    ```sh
    g++ --version
    ```

### Compilation & Execution

1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/your-username/algos-representation-app.git](https://github.com/your-username/algos-representation-app.git)
    cd algos-representation-app
    ```

2.  **Compile the source files:** The project is organized into three separate programs as per the assignment guidelines.
    ```sh
    # Compile the Fibonacci program
    g++ -o fibonacci fibonacci.cpp

    # Compile the Searching program
    g++ -o searching searching.cpp

    # Compile the Heap & Sorting program
    g++ -o heap_structures heap_structures.cpp
    ```

3.  **Run the executables:**
    ```sh
    ./fibonacci
    ./searching
    ./heap_structures
    ```

---

## 📂 Project Structure

The repository is structured to match the submission deliverables.

```
algos-representation-app/
│
├── 📄 fibonacci.cpp       # Task 1: Implementations of Fibonacci functions
├── 📄 searching.cpp       # Task 2: Implementations of search algorithms
├── 📄 heap_structures.cpp # Task 3: Heap, Priority Queue, and Heap Sort
└── 📄 README.md
```

---

## 📜 License

Distributed under the MIT License. See `LICENSE` for more information.

---

## 🙏 Acknowledgments

* This project was completed as an assignment for the **CS321 - Algorithms Analysis and Design** course.
* Special thanks to the teaching staff at the **Faculty of Computer and Artificial Intelligence, Cairo University**.
