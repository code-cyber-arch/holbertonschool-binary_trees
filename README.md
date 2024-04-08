# C - Binary Trees
In C, binary trees are a way to organize data in a tree-like structure where each node can have at most two children nodes, often called the left child and the right child. These nodes can store some data, and the structure allows for efficient searching, insertion, and deletion operations. Each node in a binary tree can have a pointer to its left child, its right child, and possibly its parent node. Binary trees are commonly used in computer science for tasks like organizing hierarchical data, implementing search algorithms, and more.
###
Here is a list of functions that can be implemented for binary trees, along with explanations of each function included in this repository.
## 0 - Create a binary tree node
This function, binary\_tree\_node,
- Creates a new binary tree node with the given value and parent node.
- Allocates memory for the new node and checks for successful allocation.
- Initializes the new node's value and parent, and sets its left and right children to NULL.
- Returns a pointer to the new node.
###
Compile using this line of code with supporting files included in build\_file folder
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
```
## 1 - Insert a node as the left-child of another node
This function, binary\_tree\_insert\_left:
- Inserts a new node as the left child of a given parent node in a binary tree.
- It first checks if the parent node is not NULL. If it is, the function returns NULL, indicating failure.
- Then, it creates a new node with the given value using the binary\_tree\_node function. If the creation of the new node fails (i.e., new\_node is NULL), the function returns NULL.
- If the parent already has a left child, the new node is inserted between the parent and its current left child. The current left child becomes the left child of the new node, and its parent pointer is updated to point to the new node.
- Finally, the function updates the parent's left pointer to point to the new node and returns a pointer to the new node.
###
Compile using this line of code with supporting files included in build\_file folder
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
```
## 2 - Insert a node as the right-child of another node

## 3 - Delete an entire binary tree

## 4 - Check if a node is a leaf

## 5 - Check if a given node is a root

## 6 - Pre-order traversal

## 7 - In-order traversal

## 8 - Post-order traversal

## 9 - Measure the height of a binary tree

## 10 - Measure the depth of a node in a binary tree

## 11 - Measure the size of a binary tree

## 12 - Count the leaves in a binary tree

## 13 - Count the nodes with at least 1 child in a binary tree

## 14 - Measure the balance factor of a binary tree

## 15 - Check if a binary tree is full

## 16 - Check if a binary tree is perfect

## 17 - Find the sibling of a node

## 18 - Find the uncle of a node

