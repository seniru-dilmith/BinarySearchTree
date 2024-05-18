# Binary Search Tree (BST) Implementation in C++

## Detailed Explanation:

### Node Structure:
- **Node** contains `data` (value), `left` (pointer to the left child), and `right` (pointer to the right child).
- The constructor initializes a new node with a given value and sets `left` and `right` pointers to `nullptr`.

### Search Operation:
- If `root` is `nullptr` or `key` is found at `root`, return `root`.
- If `key` is less than `root`'s data, recursively search in the left subtree.
- Otherwise, recursively search in the right subtree.

### Insert Operation:
- Create a new node with the given key.
- If the tree is empty, return the new node as the root.
- Traverse the tree to find the correct position for the new node.
- Insert the new node as a child of the appropriate parent node.

### Minimum and Maximum Operations:
- Traverse to the leftmost node for the minimum value.
- Traverse to the rightmost node for the maximum value.

### Successor and Predecessor Operations:
- **Successor**: If the right subtree exists, the successor is the minimum node in the right subtree. Otherwise, find the lowest ancestor for which the node is in the left subtree.
- **Predecessor**: If the left subtree exists, the predecessor is the maximum node in the left subtree. Otherwise, find the lowest ancestor for which the node is in the right subtree.

### In-order, Pre-order, Post-order Traversals:
- **In-order**: Visit left subtree, root, right subtree.
- **Pre-order**: Visit root, left subtree, right subtree.
- **Post-order**: Visit left subtree, right subtree, root.

### Delete Operation:
- **Case 1: Deleting a Leaf**:
  - If the node has no children, delete it and return `nullptr`.
- **Case 2: Deleting a Node with Only One Child**:
  - If the node has one child, delete the node and return its child.
- **Case 3: Deleting a Node with Two Children**:
  - Find the inorder successor (smallest node in the right subtree).
  - Copy the inorder successor's value to the node to be deleted.
  - Delete the inorder successor.

