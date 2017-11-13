#ifndef __BTREE_H
#define __BTREE_H

#include <iostream>

template <class T>
struct TreeNode
{
	TreeNode<T> *left, *right;

	T data;
};

template <class T>
class BTree
{
public:
	//Big Four
	BTree();
	BTree(const T, const BTree<T>&, const BTree<T>&);
	BTree(const BTree<T>&);
	BTree<T>& operator=(const BTree<T>&);

	bool empty();

private:
	TreeNode<T> *root;
};

#endif