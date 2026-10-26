# What is a Binary Search Tree (BST)

A **Binary Search Tree (BST)** is a node-based binary tree data structure where each node has at most two children. The tree properties are strictly defined by the following directional rules:
*   The left subtree of a node contains only nodes with keys lesser than the node's key.
*   The right subtree of a node contains only nodes with keys greater than the node's key.
*   Both the left and right subtrees must also be binary search trees.

Unlike self-balancing trees (like AVL trees), a standard BST does not automatically adjust its structure on insertion or deletion, meaning its height depends entirely on the order of the inputs.

---

# Common Terms

*   **Node**: A basic structural block containing an integer data payload, alongside distinct pointers directing to left and right child objects.
*   **Root**: The highest topological node in the tree structure from which all paths originate.
*   **Leaf Node**: A terminal node located at the bottom boundary of the tree containing two null child connections.
*   **Subtree**: An independent hierarchical tree structure nested entirely inside a left or right branch connection of a parent node.
*   **In-Order Successor (IS)**: The node with the smallest key value that is strictly greater than the key of a targeted node (located by tracking down the leftmost path of its right subtree).
*   **Level-Order Traversal**: A breadth-first traversal technique that reads, visits, and outputs tree elements horizontally, layer by layer, from top to bottom.

---

# Functions and Their Time Complexity (TC)

Because a basic BST does not guarantee balance, the efficiency of its search, insertion, and deletion operations scales directly with the overall tree height ($h$). In balanced configurations, $h = \text{O}(\log n)$, but if elements are inserted in a sorted or near-sorted order, the tree can degrade into a linear chain where $h = \text{O}(n)$.

### Constant Time Operations: O(1)
*   **Node(int data)**: Class constructor that instantiates a new data block with direct null child pointers.

### Logarithmic / Linear Height Bounded Operations: O(h)
*   **insert(Node\* root, int val)**: Evaluates input values recursively against parent positions to allocate and bind a new leaf node at its proper sorted coordinates.
*   **buildBTree(vector<int> arr)**: Iteratively invokes `insert` for every element provided inside an input vector array. (Total execution scales as $\text{O}(n \times h)$).
*   **Bsearch(Node\* root, int key)**: Compares target keys against current positions to drop entire subtrees from search consideration, narrowing the path down one branch line.
*   **getIS(Node\* root)**: Executes a linear downward sweep along the leftmost path of a given starting subtree to locate its minimum element.
*   **delNode(Node\* root, int key)**: Traverses down a single operational path to isolate a targeted node. Handles pointer re-linking for zero-child, one-child, or two-child node deletions seamlessly.

### Linear Time Operations: O(n)
*   **PreorderTraversal(Node\* root)**: Traces every node using a Root $\rightarrow$ Left $\rightarrow$ Right sequence path.
*   **InorderTraversal(Node\* root)**: Traces every node using a Left $\rightarrow$ Root $\rightarrow$ Right sequence path, effectively generating a completely sorted sequence of keys.
*   **PostorderTraversal(Node\* root)**: Traces every node using a Left $\rightarrow$ Right $\rightarrow$ Root sequence path.
*   **printLevelWise(Node\* root)**: Implements an iterative queue layout to track, format, and display node values line-by-line according to their horizontal layer levels.
