#ifndef TREE_HPP
#define TREE_HPP

template<typename T>
struct Node
{
	Node<T>* left;
	Node<T>* right;
	T value;

	//Constructor
	Node(T v)
	{
		value = v;
		left = nullptr;
		right = nullptr;
	}
};

template<class T>
class Tree
{
private:
	Node<T>* root;

	void addNode(T nodeVal, char* trace, Node<T>* crr);
	unsigned int countNodes(Node<T>* root);

public:
	Tree();
	//The fourth..

	//Functions
	void addNode(T nodeVal, char* trace);
	unsigned int countNodes();
};

#endif TREE_HPP