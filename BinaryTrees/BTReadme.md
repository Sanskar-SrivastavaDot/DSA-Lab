# What is a Binary Tree with Parent Pointers

A **Binary Tree** is a hierarchical data structure where each element node contains a data payload along with at most two child branches: left and right. 

Unlike standard unilateral implementations or Binary Search Trees (BST), this custom tree layout **maintains an explicit upward pointer tracking back to each node's parent**. Additionally, this implementation is unstructured, meaning node keys are placed arbitrarily by user selection during runtime without automatic positioning rules.

---

# Common Terms

*   **Node**: The core record structural component tracking value links, left/right sub-paths, and an upward parent memory pointer tracking back to its structural creator.
*   **Parent Pointer**: A complementary internal link routing from child references directly back up to their immediate caller nodes, facilitating trace paths in reverse directions.
*   **Pre-Order Sequence Serialization**: A top-down traversal layout outputting structural layers in a strict `Root` $\rightarrow$ `Left` $\rightarrow$ `Right` loop, capturing empty leaf branches with placeholders (`-1`).
*   **Arbitrary Insertion**: The direct insertion of data where placement configurations are manually determined based on targeted positional nodes instead of internal mathematical constraints.
*   **In-Order Successor Substitution**: A method used during complex node deletions where a replacement value is retrieved from the leftmost position of a node's right subtree branch.

---

# Functions and Their Time Complexity (TC)

Because the placement structure is guided entirely by runtime manual assignment configurations, structural growth behavior is unbound. Path search depth scales natively alongside total structural node height ($h$), which stays bounded in range between $\text{O}(\log n)$ and a worst-case skewed layout of $\text{O}(n)$.

### Constant Execution Functions: O(1)
*   **Node(int val, Node\* parent)**: Class constructor initializes item records, registers individual value properties, and sets baseline parent memory context instantly.

### Height Dependent Linear Sweep Functions: O(h) / O(n)
Because these modules lack sorted boundary conditions, operations must scan across arbitrary paths, making their algorithmic complexity proportional to the total number of elements ($n$) in the worst case.

*   **createTree(int val, Node\* parent)**: Builds structural tree branches recursively through real-time console input streams. 
*   **searchNode(Node\* root, int target)**: Scans left and right child paths recursively to evaluate whether a matching integer element exists.
*   **findTargetNode(Node\* root, int target)**: Traverses tree nodes to return a direct operational pointer matching target query keys.
*   **insertIntoTree(Node\* root)**: Selects parent instances via `findTargetNode` and attaches unassigned left or right nodes.
*   **findMin(Node\* root)**: Traces continuous left child lines to capture the lowest value marker within a specific branch root.
*   **deleteFromTree(Node\* root, int target)**: Clears item positions across zero-child, single-child, or double-child configurations. Coordinates parent-pointer links safely when shifting branches.

### Full-Scale Linear Tracing Functions: O(n)
*   **preOrderSequence(Node\* root)**: Outputs structured serialization paths sequentially while writing `-1` parameters for empty pointers.
*   **inOrderSequence(Node\* root)** / **postOrderSequence(Node\* root)**: Standard tree operations that touch every node exactly once to read its values.
