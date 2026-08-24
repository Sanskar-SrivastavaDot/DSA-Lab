#### Question 1: Finding the first Duplicate element in the given array.
- The solution uses two loops, first for loop selects an element arr[i] and then second for loop starts from j=i+1 and compares arr[i] and arr[j] whoever element is the first duplicate will satisfy the condition arr[i]==arr[j] and hence if this satisfies we will return arr[i] if no duplicate is in the array we will return -1;
- **Time Complexity:** $O(N^2)$, where $N$ is the number of elements in the array, due to the nested loops.
- **Space Complexity:** $O(1)$, as it operates directly on the input array without extra memory.

---

#### Question 2: Pushing the zeroes to the end of the array.
- The approach is to declare a new array of size of the given array and initialize all teh elements to zero. Using the for loop if a element is not zero then add that value to the index.That how all the non-zero elements will take the starting indexes in order.
- **Time Complexity:** $O(N)$, where $N$ is the size of the array, since it traverses the array once.
- **Space Complexity:** $O(N)$, because a new array of size $N$ is allocated to store the result.

---

#### Question 3 : If a ball is dropped to the ground with an initial speed \(s\), how many times will it bounce?
- Assuming the collision between the ball and the ground is inelastic, the speed of the ball is halved after every bounce. Hence, this approach counts how many times the speed can be divided by 2 before reaching zero.
- **Time Complexity:** $O(\log s)$, because the speed is halved at each step until it reaches a precision boundary close to zero.
- **Space Complexity:** $O(1)$, as it only requires a few variables for counting.

---

#### Question 4 : Calculating roots of Quadratic equation?
- We know that Standard form of Quadratic Equation are this \[ax^2 + bx + c = 0\].To find the roots of the equation, use the quadratic formula:  \[x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}\]
- **Time Complexity:** $O(1)$, as it performs a fixed number of basic arithmetic and square root operations.
- **Space Complexity:** $O(1)$, since no extra space scales with the input size.

---

#### Question 5 : Calculation of Time of Flight of a Projectile.
- The total time $T$ that the projectile remains in the air is given by:
\[T = \frac{2u \sin\theta}{g}\]
Where:
* $u$ = Initial velocity
* $\theta$ = Angle of projection
* $g$ = Acceleration due to gravity (approx. $9.81 \, \text{m/s}^2$)
- Input the values of speed(m/s) and angle of projection in degrees then converted it into radians to use with inbuilt function sin, Applied the formula for the ans. 
- **Time Complexity:** $O(1)$, because it uses a direct mathematical formula requiring a single computation step.
- **Space Complexity:** $O(1)$, as it only holds a few scalar variables in memory.

---
#### Question 6 : Calculation of Range of a Projectile.
- The horizontal distance $R$ covered by the projectile during its time of flight is given by:
\[R = \frac{u^2 \sin(2\theta)}{g}\]
Where:
* $u$ = Initial velocity
* $\theta$ = Angle of projection
* $g$ = Acceleration due to gravity (approx. $9.81 \, \text{m/s}^2$)
- Input the values of speed(m/s) and angle of projection in degrees then converted it into radians to use with inbuilt function sin, Applied the formula for the ans. 
- **Time Complexity:** $O(1)$, as it computes the mathematical formula directly in constant time.
- **Space Complexity:** $O(1)$, utilizing no scalable additional memory.

--- 
#### Question 7 : Calculation of Maximum Height attained by the Projectile.
- The highest vertical point $H$ reached by the projectile is given by:
\[H = \frac{u^2 \sin^2\theta}{2g}\]
- Where:
* $u$ = Initial velocity
* $\theta$ = Angle of projection
* $g$ = Acceleration due to gravity (approx. $9.81 \, \text{m/s}^2$)
- Input the values of speed(m/s) and angle of projection in degrees then converted it into radians to use with inbuilt function sin, Applied the formula for the ans. 
- **Time Complexity:** $O(1)$, since the formula executes in a single step regardless of the inputs.
- **Space Complexity:** $O(1)$, as memory usage remains fixed.

--- 
#### Question 8 : Merge two sorted Arrays.
- We create an array by taking ten values from the user. The mergeSort function divides the array into two halves again and again until every part has one element. Then the merge function compares elements from the two sorted halves, stores them in a temporary array, and copies the sorted result back to the original array. Finally, the sorted array is printed.

- **Time Complexity:** O(n log n) in best, average, and worst cases.

- **Space Complexity:** O(n) for the temporary merged array. The program uses an array of size 10 for this purpose.
---

#### Question 9 : To display the steps for moving disks in the Tower of Hanoi problem.

- Working : The algorithm moves `n` disks using a recursive divide-and-conquer strategy. It shifts the top `n-1` disks from the source to the auxiliary rod using the destination rod as storage. Next, it moves the remaining largest disk directly from the source rod to the destination rod. Finally, it shifts the `n-1` disks from the auxiliary rod to the destination rod using the source rod as storage.

- Time Complexity (TC) : $\mathcal{O}(2^n)$ because the recursive calls double with each disk, requiring exactly $2^n - 1$ total moves.

- Space Complexity (SC) : $\mathcal{O}(n)$ because it sorts in-place, using memory only for the system call stack up to a maximum depth of `n`.



