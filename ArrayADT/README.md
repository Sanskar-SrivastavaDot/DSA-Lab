## Array Based Abstract Data-Type Implementation
---
### Dynamic Array Used:
> The program instantiates a dynamic integer array (`arr`) on the heap with a user-defined fixed capacity (`cap`). It tracks the active number of elements using a count variable (`n`).

---

### Functionalities, Time Complexities, and Space Complexities:

#### 1. __Print__
* **Definition:** It loops through the array from index `0` up to `n - 1` and prints each element separated by a space. If the array has no elements (`n == 0`), it displays "Empty.".
* **Time Complexity:** $O(n)$, where $n$ is the current number of elements stored in the array, as it visits every element once.
* **Space Complexity:** $O(1)$, because it only utilizes a single tracking variable (`i`) for iteration.

#### 2. __Push__
* **Definition:** It checks if the array is full (`n >= cap`). If not, it inputs a new value and appends it to the very end of the populated array at index `n`, then increments `n`.
* **Time Complexity:** $O(1)$, since it accesses the final index directly using the tracking variable without any shifting.
* **Space Complexity:** $O(1)$, as it only requires temporary variables to read the user input.

#### 3. __Insert__
* **Definition:** It inserts a value at a specified index `idx`. It first validates boundaries and capacity. Then, it shifts all elements from index `idx` to `n - 1` one position to the right starting from the back, places the new value at `idx`, and increments `n`.
* **Time Complexity:** $O(n)$, because in the worst-case scenario (inserting at index `0`), it has to shift all $n$ elements to the right.
* **Space Complexity:** $O(1)$, as the shifting and insertion operations are handled directly inside the existing array.

#### 4. __Delete__
* **Definition:** It removes an element at a given index `idx`. After validating the index, it overwrites the element by shifting all subsequent elements from index `idx + 1` to `n - 1` one position to the left, then decrements `n`.
* **Time Complexity:** $O(n)$, since deleting from the beginning (index `0`) requires shifting all remaining $n - 1$ elements to the left.
* **Space Complexity:** $O(1)$, because the deletion and shifting happen in place without using extra array memory.

#### 5. __Search__
* **Definition:** It performs a linear scan through the array to look for a user-specified `target`. If found, it stores the index in `loc` and breaks early to print the position. Otherwise, it reports "Missing.".
* **Time Complexity:** $O(n)$, because in the worst-case scenario (the element is at the very end or absent), it must check all $n$ elements.
* **Space Complexity:** $O(1)$, as it only uses a few primitive variables (`target`, `loc`, `i`) to run the search.

---
### Overall Memory Allocation
* **Total Program Space Complexity:** $\Theta(\text{cap})$, where $\text{cap}$ is the initial capacity input by the user, since a chunk of memory matching this size is dynamically allocated on the heap for the lifetime of the execution.

