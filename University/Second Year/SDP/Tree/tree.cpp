#include "tree.hpp"

template <typename T>
Tree<T>::Tree()
{
	root = nullptr;
}

//Public
template <typename T>
void Tree<T>::addNode(T nodeVal, char* trace)
{
	addNode(nodeVal, trace, root);
}

template <typename T>
unsigned int Tree<T>::countNodes()
{
	return countNodes(root);
}

//Private
template <typename T>
void Tree<T>::addNode(T nodeVal, char* trace, Node<T>* crr)
{
	if (trace == nullptr)
	{
		root = new Node<T>(nodeVal);
		return;
	}

	if (trace[0] == 'L')
	{
		addNode(nodeVal, trace+1, root->left);
	}

	if (trace[0] == 'R')
	{
		addNode(nodeVal, trace+1, root->right);
	}
}

template <typename T>
unsigned int Tree<T>::countNodes(Node<T>* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return 1 + countNodes(root->left) + countNodes(root->right);
}