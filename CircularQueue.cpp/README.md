# CIRCULAR QUEUE : Implementaion and Functionalities
---

A Circular Queue solves this by connecting the end of the array back to the beginning. It acts like a circle, reusing empty spaces at the front of the array without needing to shift any data around.

## Data Structure used for implementation:
This implementation uses a dynamically allocated array of a fixed size (cap = 100). It keeps track of two pointers:
- st (start): Points to the first element in the queue and initialized to -1.
- end : Points to the end of the queue and initialized to -1.
When the end pointer reaches the st pointer again so the queue will be full.

## Functions and their time complexities:
1. __isEmpty():__
Checks if the queue has any elements. It does this simply by checking if the start pointer (st) is resting at -1.
- __Time Complexity:__ O(1) (Constant time)

2. isFull()
Checks if the queue is completely packed. It calculates if the very next position after end wraps around and hits st.
- __Time Complexity:__ O(1) (Constant time)

3. __add(int val)__
Often called enqueue. Adds a new integer to the back of the queue. If the queue is full, it politely warns you. Otherwise, it moves the end pointer forward (wrapping around if necessary) and places the value.

- __Time Complexity:__ O(1) (Constant time)

4. __pop()__:
Often called dequeue. Removes the element at the front of the queue and prints it. If this was the very last element in the queue, it resets both pointers back to -1. Otherwise, it just moves the st pointer forward.

- __Time Complexity:__ O(1) (Constant time)

5. __front()__
It is Often called peek. Lets you look at the first item in the line without actually removing it. If the queue is empty, it returns -1.

- __Time Complexity:__ O(1) (Constant time)

6. __display()__
Walks through the queue from the st pointer to the end pointer and prints every element in order. It handles the wrap-around seamlessly.

- __Time Complexity:__ O(N) (Linear time, where N is the number of elements currently in the queue).