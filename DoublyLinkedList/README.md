# Doubly Linked List (DLL)

A **Doubly Linked List** is a linear data structure composed of sequentially linked records called nodes. Unlike a standard singly linked list, each node contains a data field along with two distinct reference pointers: one pointing to the next node in the sequence, and another pointing back to the previous node. This bidirectional linkage allows for traversal and manipulation of the list from both the beginning (head) and the end (tail).

## Data Structure Implementation

* **Node Structure**: Every node acts as an independent object allocating memory for the stored element, a forward link (`next`), and a backward link (`prev`).
* **Head Pointer**: Tracks the very first node of the list, serving as the entry point for forward traversal.
* **Tail Pointer**: Tracks the final node of the list, enabling instant access to the end without traversing the entire structure.
* **Boundary Nodes**: The `prev` pointer of the head node and the `next` pointer of the tail node always reference `nullptr` (or `None`), signaling the boundaries of the list.

## Functions and Time Complexity

| Function | Time Complexity | Description |
| :--- | :--- | :--- |
| `append(int data)` | **O(1)** | Inserts a new node at the very end of the list. It links the new node with the current `tail` and immediately updates the `tail` pointer, executing in constant time. |
| `prepend(int data)` | **O(1)** | Inserts a new node at the very beginning of the list. It updates the links with the current `head` and shifts the `head` pointer forward, executing in constant time. |
| `remove(int data)` | **O(N)** | Deletes a node containing specific data. In the worst-case scenario, it must traverse all $N$ elements sequentially to locate the target node before updating the surrounding pointers and freeing memory. |
| `displayForward()` | **O(N)** | Begins at the `head` pointer and visits every single node sequentially until reaching `nullptr`. It prints each node's data field along the way, scaling linearly with the number of nodes. |
