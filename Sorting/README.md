# Sorting Algorithms:

## 1. Bin Sort (Bucket Sort)

Bin Sort distributes elements into multiple sub-containers called **bins or buckets**. Each bin is then sorted individually, either using a different sorting algorithm or by recursively applying bin sort.

### Implementation Logic
*   Find the minimum and maximum values in the array to determine the data range.
*   Create an array of empty bins (usually equal to the number of elements $n$).
*   Iterate through the input array and map each element to a specific bin index using a mapping formula:
    $$\text{binIndex} = \frac{(\text{arr}[i] - \text{min}) \times (n - 1)}{\text{range}}$$
*   Sort each individual bin using a stable sorting method (like Insertion Sort or standard library sort).
*   Concatenate the elements from all bins back into the original array sequentially.

### Time Complexity Explanation
*   **Best & Average Case: $\mathcal{O}(n + k)$** — When data is uniformly distributed, elements split evenly across bins. If sorting individual bins takes linear or near-linear time, the overall operation runs exceptionally fast. ($k$ represents the number of bins).
*   **Worst Case: $\mathcal{O}(n^2)$** — If the data is heavily skewed or clustered, all elements may fall into a single bin. The complexity then degrades to the sorting algorithm used to clear out that specific bin.

---

## 2. Merge Sort

Merge Sort is a stable algorithm based on the **Divide and Conquer** paradigm. It continuously splits an array into halves, sorts them, and joins them back together.

### Implementation Logic
*   **Divide:** Locate the midpoint of the array using `mid = low + (high - low) / 2` and split it into left and right subarrays.
*   **Conquer:** Recursively break down the subarrays until subarrays of size 1 are reached (which are inherently sorted).
*   **Combine:** Merge the small, sorted subarrays back into a single ordered array by comparing elements side-by-side using two tracking indices.

### Time Complexity Explanation
*   **Best, Average, & Worst Case: $\mathcal{O}(n \log n)$** — The array is split into two halves at every level, creating a balanced binary recursion tree of depth $\log_2 n$. At each level of the tree, the merge function takes linear time $\mathcal{O}(n)$ to compare and combine elements. Because the splitting pattern does not depend on data distribution, the performance remains perfectly consistent in all cases.

---

## 3. Radix Sort

Radix Sort is a non-comparative sorting algorithm that processes data with integer keys by grouping keys by individual digits that share the same **significant position and value (radix)**.

### Implementation Logic
*   Find the maximum element in the array to know the maximum number of digits ($d$).
*   Set up a loop that processes the array digit by digit, starting from the least significant digit (1s place) up to the most significant digit (10s, 100s, etc.).
*   In each iteration, use a stable sorting algorithm—typically **Counting Sort**—as a subroutine to sort elements based on the current digit.
*   Maintain the relative order of elements with identical digits to preserve overall structural sorting stability.

### Time Complexity Explanation
*   **Best, Average, & Worst Case: $\mathcal{O}(d \times (n + b))$** — The algorithm repeats its sorting routine exactly $d$ times (where $d$ is the number of digits in the largest number). In each pass, Counting Sort takes linear time relative to the number of elements $n$ and the base of the number system $b$ (for decimal numbers, the base $b = 10$). 

---

## 4. Quick Sort

Quick Sort is an in-place sorting algorithm that uses the **Divide and Conquer** approach. It selects a benchmark element called a **pivot** and arranges the remaining data around it.

### Implementation Logic
*   Select a **pivot** element from the array (commonly the last element, first element, or a random index).
*   **Partition:** Rearrange the array so that all elements smaller than or equal to the pivot move to its left, and all elements larger move to its right.
*   Place the pivot element in its exact final sorted position and return its index (`pi`).
*   Recursively apply the same workflow to the left sub-array (from `low` to `pi - 1`) and the right sub-array (from `pi + 1` to `high`).

### Time Complexity Explanation
*   **Best & Average Case: $\mathcal{O}(n \log n)$** — Occurs when the partition step consistently splits the array into two nearly equal halves. This creates a recursion tree depth of $\log n$, with linear $\mathcal{O}(n)$ partitioning work performed at each level.
*   **Worst Case: $\mathcal{O}(n^2)$** — Occurs when the pivot is consistently the smallest or largest element (e.g., trying to sort an already sorted array using the first or last element as the pivot). This results in highly unbalanced partitions of size $0$ and $n-1$, creating a skewed recursion tree of depth $n$.

## Merge Sort Using Linked Lists: 

### Implementation lOgic: 
- The algorithm splits the linked list into two halves recursively using a slow and fast pointer strategy until sublists of size one are reached. It isolates the halves by setting the mid node's next pointer to null, then sorts both independent lists recursively. To combine them, the merge function sets its initial head pointer based on the smaller first element and chains subsequent nodes through a structural look-ahead pointer tracking comparisons. This structural approach sorts the entire list safely in place by rewiring pointer addresses without allocating dummy tracking nodes.

## Time Complexity (TC)
$\mathcal{O}(n \log n)$ across all cases because the list is always divided into equal halves, taking linear time to find the mid and merge elements at every level of the recursive call tree.

## Space Complexity (SC)
$\mathcal{O}(\log n)$ because it updates the list entirely in-place by changing internal pointers, using space only for the system execution call stack during recursion.

## 5. Bubble Sort (Optimized Iterative Approach)

Bubble Sort repeatedly steps through the array, compares adjacent elements, and **swaps them if they are in the wrong order**. This pass-through is repeated until the array is fully sorted.

### Implementation Logic
*   Run nested loops where the outer loop tracks the total number of passes and the inner loop compares adjacent elements.
*   In each pass, compare `arr[j]` and `arr[j + 1]`. If `arr[j] > arr[j + 1]`, swap the elements.
*   Optimize the process by using a boolean `swapped` tracking flag. Set it to `false` at the start of each pass.
*   If a swap occurs, flip the flag to `true`. If the inner loop finishes a full pass with the flag remaining `false`, break early as the array is already sorted.

### Time Complexity Explanation
*   **Best Case: $\mathcal{O}(n)$** — Occurs when the input array is already sorted. The optimized tracking flag detects that no swaps were made during the very first pass and terminates the execution immediately.
*   **Average & Worst Case: $\mathcal{O}(n^2)$** — Occurs when the array is randomly distributed or sorted in absolute reverse order. The algorithm must execute nested comparison passes, resulting in a quadratic number of total checks and swap operations.

---

## 6. Selection Sort (Bidirectional / Double Selection Approach)

Selection Sort divides the array into sorted and unsorted boundaries. The bidirectional variant (Double Selection Sort) optimizes this by **finding both the minimum and maximum elements in a single pass**, moving them to their respective ends simultaneously.

### Implementation Logic
*   Maintain two pointers tracking the boundaries of the unsorted segment: `start` at the beginning and `end` at the tail.
*   In each pass, iterate from `start` to `end` to find the indices of both the absolute minimum (`minIdx`) and absolute maximum (`maxIdx`) values.
*   Swap the element at `start` with the element at `minIdx`.
*   Check if the maximum element was originally sitting at the `start` index. If it was, update `maxIdx` to point to `minIdx` since its position was just shifted.
*   Swap the element at `end` with the element at `maxIdx`.
*   Narrow the unsorted workspace by incrementing `start` and decrementing `end`, repeating until the pointers cross.

### Time Complexity Explanation
*   **Best, Average, & Worst Case: $\mathcal{O}(n^2)$** — Although this bidirectional optimization cuts the total number of scanning sweeps in half ($\sim n/2$ passes), each pass must still scan every single remaining element to guarantee that the absolute minimum and maximum indices are found. Because this full scan runs regardless of the initial order of the data, the runtime scales quadratically across all execution scenarios.

---

## 7. Insertion Sort (Binary Search-Based Approach)

Insertion Sort maintains a sorted partition at the front of the array and inserts new elements into their correct positions one by one. The binary variant optimizes this by **using binary search to find the insertion index** instead of scanning linearly backward.

### Implementation Logic
*   Iterate through the array starting from the second element (index 1), treating it as the target `key` to be inserted.
*   Initialize a binary search zone within the sorted prefix array running from index `0` to `i - 1`.
*   Execute a standard binary search loop (`low` to `high`) to isolate the exact target index where `key` belongs, terminating when `low` pinpoints the insertion boundary.
*   Shift all elements from index `i - 1` down to `low` forward by one position to open up an empty slot.
*   Drop the `key` element directly into the vacant slot at index `low`.

### Time Complexity Explanation
*   **Best Case: $\mathcal{O}(n)$** — When the array is completely sorted, the binary search finds the correct slot instantly, and the shifting loop condition resolves to zero operations. The algorithm simply verifies each element in linear time.
*   **Average & Worst Case: $\mathcal{O}(n^2)$** — Using a binary search successfully cuts down the total comparison overhead to $\mathcal{O}(n \log n)$. However, the algorithm still requires shifting elements in memory to open slots for insertion. In the worst and average cases, shifting elements continues to demand quadratic $\mathcal{O}(n^2)$ operations, which dominates the overall runtime complexity.
