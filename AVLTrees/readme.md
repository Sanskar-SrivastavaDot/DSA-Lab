# What is an AVL Tree

An **AVL tree** is a self-balancing binary search tree (BST) where the difference between the heights of the left and right subtrees for any node cannot be more than 1. If at any point this height difference changes by more than 1, the tree performs structural pointer rotations to balance itself again. This guarantees that basic tree operations remain highly efficient.

---

# Common Terms

*   **Node**: The basic data element containing a value (key), pointers to left and right children, and a calculated height value.
*   **Root**: The very top node of the tree from which all other branches originate.
*   **Leaf Node**: A node at the bottom of the tree that has no children (both left and right pointers are null).
*   **Subtree**: A smaller tree structure contained entirely within a parent node's branch.
*   **Height**: The total number of edges on the longest downward path from a specific node to a leaf node. Empty spaces have a height of 0.
*   **Balance Factor**: The integer result of subtracting the height of the right subtree from the height of the left subtree (`Left Height - Right Height`).
*   **Imbalance**: A state where a node's balance factor becomes greater than 1 or less than -1, requiring correction.
*   **Rotation**: A localized pointer manipulation process that moves a child node up into a parent node's position to correct a balance factor.

---

# Functions and Their Time Complexity (TC)

Because the tree maintains a strict balanced state, the maximum height of the tree is always bounded to **O(log n)**, where *n* is the total number of nodes. This directly determines the efficiency of the operations below:

### Constant Time Operations: O(1)
*   **h(Node\* n)**: Safely extracts the internal integer height value from a targeted node. Uses a quick ternary condition to catch null pointers instantly.
*   **getBalanceFactor(Node\* n)**: Computes the structural offset of a node by finding the exact difference between its left and right children's heights.
*   **rotateLeft(Node\* parent) / rotateRight(Node\* parent)**: Rearranges local child-parent pointers to flip tree weight. Recalculates heights locally without scanning deep into subtrees.
*   **rotateLeftRight(Node\* n) / rotateRightLeft(Node\* n)**: Multi-step balancing helpers that trigger two basic rotation functions back-to-back.
*   **balanceTree(Node\* root)**: A localized control hub that evaluates balance factor conditions and triggers up to two basic rotations on a single path.

### Logarithmic Time Operations: O(log n)
*   **minNode(Node\* root)**: Runs down the leftmost path of a subtree to pull the smallest key value. Execution duration is tied directly to the height of that specific branch.
*   **insert(Node\* root, char data)**: Steps down a single path from the root to locate an open leaf space for a new node. Updates heights and checks balance parameters automatically as the recursion unwinds.
*   **remove(Node\* root, char target)**: Follows a specific branch path to delete a node. If the node has two children, it makes a quick secondary pass down a sub-branch to find its in-order successor using `minNode`.

### Linear Time Operations: O(n)
*   **printInOrder(Node\* root)**: Visits every active node exactly once to print out all stored keys in a sorted sequence.
