
## **Array-Based Abstract Data Type Implementation**
---
### Variables and State:
> The program uses an integer variable `cap` to define the maximum storage, a dynamically allocated raw array pointer `arr`, and an integer variable `n` tracking the current number of elements present (instantiated at `0`).

### Storage Mechanics:
> A contiguous block of memory is allocated dynamically on the heap (`new int[cap]`). Elements are stored sequentially up to the fixed capacity without any Object-Oriented class abstractions or overhead.

### Functionalities added to Array:

- **Print (Action 1)**: A simple loop that iterates through the array from index `0` to `n-1` and prints the stored values one by one. If `n` is `0`, it outputs "Empty.".
- **Push (Action 2)**: Adds an element directly to the end of the array at index `n` and increments `n` by 1. It checks if `n >= cap` first, returning "Full!" if no space remains.
- **Insert (Action 3)**: Places an element at a specific index by shifting all subsequent items one position to the right using a backward `while` loop starting from `n`. It validates bounds and capacity before execution.
- **Delete (Action 4)**: Deletes an element at a given index by shifting all subsequent items one position to the left using a `for` loop, then decrements `n` by 1. It checks for invalid out-of-bounds indices.
- **Search (Action 5)**: Searches for a target value sequentially from index `0` to `n-1`. If found, it returns the index position; otherwise, it outputs "Missing.".
