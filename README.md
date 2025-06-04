# 🧠 Data Structures and Algorithms (DSA) Repository

This repository contains a wide variety of Data Structures and Algorithms implemented primarily in **C++**, with some algorithms also written in **Java**. The goal is to strengthen my understanding of DSA through hands-on coding and make these implementations available for anyone learning or revising DSA.

---

## 📁 Project Structure


Each folder contains source files related to that specific data structure or algorithm type.

---

## ✅ Implemented Topics

### 🔗 Linked Lists
- Singly Linked List
- Doubly Linked List
- Circular Linked List
- Multi Linked List

### 📦 Stacks and Queues
- Array-based Stack and Queue
- Linked List-based Stack and Queue

### 🌲 Trees
- Binary Search Tree (BST)
- AVL Tree (Self-balancing Binary Tree)

### 📊 Graphs
- DFS and BFS using:
  - Adjacency List
  - Adjacency Matrix
- Directed and Undirected Graphs supported

### 🧮 Sorting Algorithms
- Quick Sort
- Bubble Sort
- Selection Sort
- Insertion Sort

### 🔐 Hashing Techniques
- Open Hashing (Chaining)
- Closed Hashing (Linear and Quadratic Probing and double quadratic probing)

### ⛏️ Heap
- Min Heap (implemented using arrays)

### 📌 Graph Algorithms
- Dijkstra’s Algorithm (Shortest Path)
- Kruskal’s Algorithm (Minimum Spanning Tree)
- Prim’s Algorithm (Minimum Spanning Tree)

---

## 🧾 Sample Code Snippet (C++ - Min Heap Insert)

```cpp
void MinHeap::insert(int key) {
    heap.push_back(key);
    int i = heap.size() - 1;
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
