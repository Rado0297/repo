#include "BTree.hpp"

#include <iostream>
#include <cassesrt>

bool BTree<T>::empty()
{
	return root == NULL;
}