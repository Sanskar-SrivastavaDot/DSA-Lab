# Stack Data Structure

A **Stack** is a linear data structure that operates under the **LIFO (Last In, First Out)** principle. The element inserted last is the first one to be extracted. 

---

## 1. Array Implementation

This approach uses a static block of memory. A structural variable `topIndex` tracks the array index of the top element. It starts at `-1` when the stack is empty.

### Functions & Time Complexities

*   **`push(val)`**
    *   **Logic:** Increments `topIndex` by 1 and places `val` at `arr[topIndex]`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Direct index access.
*   **`pop()`**
    *   **Logic:** Decrements `topIndex` by 1 to effectively remove the element.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Decrementing a pointer takes constant time.
*   **`peek()` / `top()`**
    *   **Logic:** Evaluates and returns the element at `arr[topIndex]`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Direct index lookup.
*   **`isEmpty()`**
    *   **Logic:** Validates if `topIndex == -1`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Single equality evaluation.

---

## 2. Linked List Implementation

This approach uses dynamically allocated nodes. A reference pointer `topNode` always targets the head node of the linked list. 

### Functions & Time Complexities

*   **`push(val)`**
    *   **Logic:** Instantiates a new node, points its `next` pointer to `topNode`, and shifts `topNode` to target this new node.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Pointer reassignment takes absolute constant time.
*   **`pop()`**
    *   **Logic:** Copies `topNode` to a temporary reference, updates `topNode` to `topNode->next`, and clears the memory of the temporary node.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Adjusting the head node pointer takes constant time.
*   **`peek()` / `top()`**
    *   **Logic:** Reads and returns `topNode->data`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Immediate pointer dereferencing.
*   **`isEmpty()`**
    *   **Logic:** Validates if `topNode == nullptr`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Single pointer verification.

---

## Doubly Linked List Implementation

This variant uses nodes containing data alongside `next` and `prev` pointers. A single tracking pointer `top` manages all stack insertions and deletions.

### Functions & Time Complexities

*   **`push(v)`**
    *   **Logic:** Spawns a node, wires its `prev` link to `top`, points `top->next` forward, and sets `top` to the new node.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Constant time pointer links.
*   **`pop()`**
    *   **Logic:** Retracts `top` to `top->prev`, severs the dead link, and drops the old head node from memory.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Step-back pointer shift runs in constant time.
*   **`peek()`**
    *   **Logic:** Looks up and returns the integer held at `top->val`.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Direct memory reference read.
*   **`isEmpty()`**
    *   **Logic:** Verifies if `top` resolves to a null pointer.
    *   **Time Complexity:** $\mathcal{O}(1)$ — Single pointer verification.

