Balanced Binary Tree (Please refer to the docx version of README for better understanding)


A binary tree is considered balanced if the difference between the heights of the left and the right subtree is not more than 1 for any given node.

Given the root node of a binary tree, determine whether it's height balanced.

balanced-binary-tree
Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 2 lines:

The first line contains an integer n denoting the number of nodes in the tree (including the NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
Output Format
For each test case, the output contains a line with 1 or 0 based on whether the tree is balanced or not respectively.

Sample Input
5
7
1 2 -1 4 -1 5 6
3
6 -1 4
7
8 -1 9 -1 10 11 12
5
28 14 11 -1 48
1
6
Expected Output
0
1
0
1
1