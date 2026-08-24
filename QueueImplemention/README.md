# Queue Data Structure

A **Queue** is a linear data structure that operates under the **FIFO (First In, First Out)** principle. The element inserted first is the first one to be extracted.

---

## 1. Array Implementation

This approach uses a linear, fixed-size memory array. It tracks the front element using `frontIndex` and the back element using `rearIndex`. When elements are removed, the front index moves forward, meaning older memory blocks are left empty and cannot be reused.

### Functions & Time Complexities

*   **`enqueue(val)`**
    *   **Logic:** Increments `rearIndex` by 1 and places `val` at `arr[rearIndex]`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Direct index assignment.
*   **`dequeue()`**
    *   **Logic:** Increments `frontIndex` by 1 to shift past the removed element. 
    *   **Time Complexity:** $\mathcal{O}(1)$ — Increments a tracking pointer in constant time.
*   **`getFront()`**
    *   **Logic:** Evaluates and returns the item located at `arr[frontIndex]`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Direct index lookup.
*   **`isEmpty()`**
    *   **Logic:** Validates if `frontIndex > rearIndex`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Single comparison evaluation.

---

## 2. Linked List Implementation

This approach uses independent dynamic nodes. It maintains two distinct pointers: a `head` pointer to handle extractions (deletions) and a `tail` pointer to manage insertions.

### Functions & Time Complexities

*   **`enqueue(val)`**
    *   **Logic:** Allocates a new node, links it to `tail->next`, and shifts the `tail` pointer to target the new node.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Instant insertion via the explicit `tail` tracking pointer.
*   **`dequeue()`**
    *   **Logic:** References the current `head` node, advances `head` to `head->next`, and clears the isolated node from memory.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Deletion occurs entirely at the front in constant time.
*   **`getFront()`**
    *   **Logic:** Reads and returns `head->data`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Immediate pointer dereferencing.
*   **`isEmpty()`**
    *   **Logic:** Validates if `head == nullptr`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Single pointer verification.
---

## Doubly Linked List Implementation

This variant uses structural nodes containing bidirectional pointers. It leverages a front pointer `head` for deletions and a back pointer `tail` for insertions.

### Functions & Time Complexities

*   **`enqueue(v)`**
    *   **Logic:** Allocates a node, fastens it right after `tail`, links the node's `prev` pointer back, and advances `tail`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Direct insertion via the back index pointer.
*   **`dequeue()`**
    *   **Logic:** Tracks `head`, moves `head` to `head->next`, wipes out the backward link, and deletes the extracted node.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Removes the oldest element in absolute constant time.
*   **`getFront()`**
    *   **Logic:** Fetches and returns the value inside `head->val`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Instant pointer tracking lookup.
*   **`isEmpty()`**
    *   **Logic:** Assesses whether `head` evaluates to null.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Immediate evaluation check.

