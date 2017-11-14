#include <iostream>
#include <string>

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

template <typename T>
unsigned int Tree<T>::countEvenNodes()
{
	return countEvenNodes(root);
}

//Private
template <typename T>
void Tree<T>::addNode(T nodeVal, char* trace, Node<T> *&crr)
{
	if (trace[0] == '\0')
	{
		crr = new Node<T>(nodeVal);
		return;
	}

	if (trace[0] == 'L')
	{
		addNode(nodeVal, trace+1, crr->left);
		return;
	}

	if (trace[0] == 'R')
	{
		addNode(nodeVal, trace+1, crr->right);
		return;
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

template <typename T>
unsigned int Tree<T>::countEvenNodes(Node<T>* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	if (root->value % 2 == 0)
	{
		return 1 + countEvenNodes(root->left) + countEvenNodes(root->right);
	}

	return countEvenNodes(root->left) + countEvenNodes(root->right);
}