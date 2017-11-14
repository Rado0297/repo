#include <iostream>
#include <string>

#include "tree.cpp"

void testAddNodes()
{
	Tree<int> t;
	t.addNode(1, "");
	t.addNode(2, "L");
	t.addNode(3, "R");
	t.addNode(4, "LL");
	t.addNode(5, "LR");
	t.addNode(6, "RR");
	t.addNode(7, "RRR");

	std::cout << "Count of tree nodes: " << t.countNodes() << std::endl;
}

void testEvenCountTree()
{
	Tree<int> t;
	t.addNode(1, "");
	t.addNode(2, "L");
	t.addNode(3, "R");
	t.addNode(4, "LL");
	t.addNode(5, "LR");
	t.addNode(6, "RR");
	t.addNode(7, "RRR");

	std::cout << "Count of even tree nodes: " << t.countEvenNodes() << std::endl;
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
	testEvenCountTree();

	
	return 0;
}