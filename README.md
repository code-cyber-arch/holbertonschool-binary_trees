# C - Binary Trees
In C, binary trees are a way to organize data in a tree-like structure where each node can have at most two children nodes, often called the left child and the right child. These nodes can store some data, and the structure allows for efficient searching, insertion, and deletion operations. Each node in a binary tree can have a pointer to its left child, its right child, and possibly its parent node. Binary trees are commonly used in computer science for tasks like organizing hierarchical data, implementing search algorithms, and more.
###
Here is a list of functions that can be implemented for binary trees, along with explanations of each function included in this repository.
## 0 - Create a binary tree node
This C function, [binary\_tree\_node](https://github.com/amirasabdu/holbertonschool-binary_trees/blob/main/0-binary_tree_node.c),
- Creates a new binary tree node with the given value and parent node.
- Allocates memory for the new node and checks for successful allocation.
- Initializes the new node's value and parent, and sets its left and right children to NULL.
- Returns a pointer to the new node.
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
```
## 1 - Insert a node as the left-child of another node
This C function, [binary\_tree\_insert\_left](https://github.com/amirasabdu/holbertonschool-binary_trees/blob/main/1-binary_tree_insert_left.c):
- Inserts a new node as the left child of a given parent node in a binary tree.
- It first checks if the parent node is not NULL. If it is, the function returns NULL, indicating failure.
- Then, it creates a new node with the given value using the binary\_tree\_node function. If the creation of the new node fails (i.e., new\_node is NULL), the function returns NULL.
- If the parent already has a left child, the new node is inserted between the parent and its current left child. The current left child becomes the left child of the new node, and its parent pointer is updated to point to the new node.
- Finally, the function updates the parent's left pointer to point to the new node and returns a pointer to the new node.
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
```
## 2 - Insert a node as the right-child of another node
This C function, [binary\_tree\_insert\_right](https://github.com/amirasabdu/holbertonschool-binary_trees/blob/main/2-binary_tree_insert_right.c) inserts a new node as the right child of a specified parent node in a binary tree:
- First, it checks if the parent is NULL; if so, it returns NULL.
- It creates a new node with the given value. If creation fails, it returns NULL.
- If the parent already has a right child, the function places the new node between the parent and its current right child, updating the necessary parent-child relationships.
- The new node is set as the right child of the parent.
- The function returns the new node, indicating successful insertion.
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right
```
## 3 - Delete an entire binary tree
The [binary\_tree\_delete](https://github.com/amirasabdu/holbertonschool-binary_trees/blob/main/3-binary_tree_delete.c) function recursively frees an entire binary tree:
- It first checks if the current node (tree) is not NULL.
- It recursively calls itself to delete the left subtree, then the right subtree.
- Finally, it frees the current node, ensuring the entire tree is deleted from memory.
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del
```
## 4 - Check if a node is a leaf
The [binary\_tree\_is\_leaf](https://github.com/amirasabdu/holbertonschool-binary_trees/blob/main/4-binary_tree_is_leaf.c) function checks if a given node in a binary tree has no children:
- If the node is NULL, it returns 0.
- If both the left and right children of the node are NULL, it returns 1, indicating the node is a leaf.
- Otherwise, it returns 0.
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 4-binary_tree_is_leaf.c 4-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf
```
## 5 - Check if a given node is a root
The [binary\_tree\_is\_root](https://github.com/amirasabdu/holbertonschool-binary_trees/blob/main/5-binary_tree_is_root.c) function checks if a given node in a binary tree is a root node:
- It returns 1 if the node is not NULL and has no parent (node-\>parent == NULL), indicating it is a root.
- Otherwise, it returns 0.
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 5-binary_tree_is_root.c 5-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root
```
## 6 - Pre-order traversal

The [binary\_tree\_preorder](https://github.com/amirasabdu/holbertonschool-binary_trees/blob/main/6-binary_tree_preorder.c) function performs a pre-order traversal of a binary tree, calling a given function on each node's value:
- If either the tree pointer or the function pointer is NULL, the function returns.
- It calls the function on the current node's value.
- It recursively traverses the left subtree.
- It recursively traverses the right subtree.
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre
```
## 7 - In-order traversal
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in
```
## 8 - Post-order traversal
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post
```
## 9 - Measure the height of a binary tree
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 9-binary_tree_height.c 9-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height
```
## 10 - Measure the depth of a node in a binary tree
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 10-binary_tree_depth.c 10-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth
```
## 11 - Measure the size of a binary tree
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 11-binary_tree_size.c 11-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 11-size
```
## 12 - Count the leaves in a binary tree
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 12-binary_tree_leaves.c 12-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 12-leaves
```
## 13 - Count the nodes with at least 1 child in a binary tree
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 13-binary_tree_nodes.c 13-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 13-nodes
```
## 14 - Measure the balance factor of a binary tree
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 14-binary_tree_balance.c 14-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c -o 14-balance
```
## 15 - Check if a binary tree is full
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 15-binary_tree_is_full.c 15-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 15-full
```
## 16 - Check if a binary tree is perfect
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 16-binary_tree_is_perfect.c 16-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 16-perfect
```
## 17 - Find the sibling of a node
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 17-main.c 17-binary_tree_sibling.c 0-binary_tree_node.c -o 17-sibling
```
## 18 - Find the uncle of a node
###
Compile using this line of code with supporting files included in [build\_file](https://github.com/amirasabdu/holbertonschool-binary_trees/tree/main/build_files)
```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 18-main.c 18-binary_tree_uncle.c 0-binary_tree_node.c -o 18-uncle
```
