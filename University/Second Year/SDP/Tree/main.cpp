#include <iostream>

#include "tree.cpp"

void testAddNodes()
{
	Tree<int> t;
	t.addNode(1, "");
	t.addNode(2, "L");
	t.addNode(3, "R");
	t.addNode(4, "L");
	t.addNode(5, "L");
	t.addNode(6, "R");
	t.addNode(7, "L");
	t.addNode(8, "R");
	t.addNode(9, "R");
	t.addNode(10, "R");
	t.addNode(11, "R");

	std::cout << "Count of tree nodes: " << t.countNodes() << std::endl;
}

void testCountTree()
{
	Tree<int> t;
	std::cout << "Count of empty tree nodes: " << t.countNodes() << std::endl;
}

int main()
{
	testAddNodes();
	testCountTree();


	
	return 0;
}