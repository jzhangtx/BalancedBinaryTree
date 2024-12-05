BalancedBinaryTree: BalancedBinaryTree.o
	g++ -g -o BalancedBinaryTree.exe BalancedBinaryTree.o -pthread    

BalancedBinaryTree.o: BalancedBinaryTree/BalancedBinaryTree.cpp
	g++ -g  -c -pthread BalancedBinaryTree/BalancedBinaryTree.cpp
