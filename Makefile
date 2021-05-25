hw2: hw2 main.o BinaryNode.o BinarySearchTree.o
	g++ -o hw2 main.o BinaryNode.o BinarySearchTree.o

hw: BinarySearchTree.cpp main.cpp BinaryNode.cpp
	g++ -c main.cpp BinarySearchTree.cpp BinaryNode.cpp

clean: hw2 main.o
	rm hw2 main.o