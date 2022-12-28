#include <iostream>
#include "Tree.h"

template<typename T>
Tree<T>::template Iterator Tree<T>::Begin()
{
	Node<T>* node = _top;

	while (node->right)
	{
		node = node->right;
	}

	Iterator iter(node, node->tata);

	return iter;
}

template<typename T>
Tree<T>::template Iterator Tree<T>::End()
{
	Node<T>* node = _top;

	while (node->left)
	{
		node = node->left;
	}

	Iterator iter(node, node->tata);

	return iter;
}

template<typename T>
T& Tree<T>::Iterator::operator++(int b)
{
	if (_initialNode->left == nullptr)
	{
		do
		{
			_prevNode = _initialNode;
			_initialNode = _initialNode->tata;
		
		} while (_initialNode != nullptr && _prevNode->data < _initialNode->data);
	}
	else 
	{
		_initialNode = _initialNode->left;
		
		while (_initialNode->right)
		{
			_initialNode = _initialNode->right;
		}
	}

	return _initialNode->data;
}

template<typename T>
T& Tree<T>::Iterator::operator--(int b)
{ 
	if (_initialNode->right == nullptr)
	{
		do
		{
			_prevNode = _initialNode;
			_initialNode = _initialNode->tata;

		} while (_initialNode != nullptr && _prevNode->data > _initialNode->data);
	}
	else
	{
		_initialNode = _initialNode->right;

		while (_initialNode->left)
		{
			_initialNode = _initialNode->left;
		}
	}

	return _initialNode->data;
}

template<typename T>
bool Tree<T>::Iterator::operator!=(const Iterator& b)
{
	if (_initialNode->data != b._initialNode->data)
	{
		return true;
	}

	return false;
}

template<class T>
bool Tree<T>::Iterator::operator==(const Iterator& b)
{
	if (_initialNode->data == b._initialNode->data)
	{
		return true;
	}

	return false;
}
