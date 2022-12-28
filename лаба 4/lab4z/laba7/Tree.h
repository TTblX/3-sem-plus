#pragma once
#include <iostream>
#include "Clock.h"

using namespace std;

template <class T>
struct Node
{
	T data;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
	explicit Node(T);
	void WriteNodeToFile(std::fstream& file);
	~Node() = default;
};

template<class T>
Node<T>::Node(T data) : data(data)
{
}

template<class T>
inline void Node<T>::WriteNodeToFile(std::fstream& file)
{
	file << data << endl;

	if (left != nullptr) left->WriteNodeToFile(file);
	if (right != nullptr) right->WriteNodeToFile(file);
}

template <class T>
class Tree
{
private:
	Node<T>* _top;
public:
	Tree()
	{
		_top = nullptr;
	}

	~Tree() = default;

	Node<T>* Push(T, Node<T>*, Node<T>*);

	void Show(const string& prefix, const Node<T>* node, bool isLeft);

	int Pop(T&, Node<T>*);

	void SetTop(Node<T>* top)
	{
		_top = top;
	}

	Node<T>* GetTop()
	{
		return _top;
	}

	class Iterator
	{
	private:
		Node<T>* _initialNode;
		Node<T>* _prevNode;
	public:
		Iterator() : _initialNode(nullptr), _prevNode(nullptr)
		{
		}

		Iterator(Node<T>* inNode, Node<T>* top) : _initialNode(inNode), _prevNode(top)
		{
		}

		Node<T>* GetInNode()
		{
			return _initialNode;
		}

		T& operator++(int b);

		T& operator--(int b);

		T& operator*()
		{
			return _initialNode->data;
		}

		bool operator==(const Iterator& b);

		bool operator!=(const Iterator& b);
	};

	Iterator Begin();
	Iterator End();

};


template<class T>
Node<T>* Tree<T>::Push(T data, Node<T>* node, Node<T>* parent)
{
	if (node == nullptr)
	{
		Node<T>* node = new Node<T>(data);
		node->left = nullptr;
		node->right = nullptr;
		node->parent = parent;
		return node;
	}

	if (node->data == data)
	{
		return node;
	}

	if (node->data > data)
	{
		node->left = Push(data, node->left, node);
	}

	if (node->data < data)
	{
		node->right = Push(data, node->right, node);
	}

	return node;
}

template<typename T>
void Tree<T>::Show(const string& prefix, const Node<T>* node, bool isLeft)
{	
	if (node == nullptr && GetTop() == nullptr) throw ArgumentIsEmptyException("Tree");

	if (node != nullptr)
	{
		cout << prefix;

		cout << (isLeft ? "|---" : "'---");

		// print the value of the node
		cout << node->data << std::endl;

		// enter the next tree level - left and right branch
		Show(prefix + (isLeft ? "|   " : "    "), node->left, true);
		Show(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
	
}

template<typename T>
int Tree<T>::Pop(T& element, Node<T>* top)
{
	Node<T>* nodeRem = top;
	bool flg = 0;

	for (Tree<T>::Iterator it = Begin(); it != End(); it++)
	{
		if (*it == element)
		{
			nodeRem = it.GetInNode();
			flg = 1;
			break;
		}
	}

	if (flg)
	{
		if (nodeRem->left == nodeRem->right)
		{
			nodeRem = nodeRem->parent;

			return -1;
		}

		if (nodeRem == top)
		{
			if (top->left)
			{
				if (top->left->right)
				{
					nodeRem = top->left->right;
					while (nodeRem->right != nullptr)
					{
						nodeRem = nodeRem->right;
					}
				}

				nodeRem->right = top->right;
				top = top->left;

				_top = top;
				_top->parent = nullptr;
			}
			else if (top->right)
			{
				top = top->right;

				_top = top;
				_top->parent = nullptr;
			}

			return 0;
		}
		else
		{
			Node<T>* prevNode = nodeRem->parent;
			Node<T>* specNode = nodeRem;

			if (nodeRem->data < prevNode->data)
			{
				if (nodeRem->right)
				{
					specNode = nodeRem->right;
					while (specNode->left != nullptr)
					{
						specNode = specNode->left;
					}

					prevNode->left = nodeRem->right;
					if (nodeRem->right != nullptr)
					{
						nodeRem->right->parent = prevNode;
					}
					specNode->left = nodeRem->left;
				}
				else
				{
					prevNode->left = nodeRem->left;
					if (nodeRem->left != nullptr)
					{
						nodeRem->left->parent = prevNode;
					}
				}
			}
			else
			{
				if (nodeRem->left)
				{
					specNode = nodeRem->left;
					while (specNode->right)
					{
						specNode = specNode->right;
					}

					prevNode->right = nodeRem->left;
					if (nodeRem->left != nullptr)
					{
						nodeRem->left->parent = prevNode;
					}

					specNode->right = nodeRem->right;
				}
				else
				{
					prevNode->right = nodeRem->right;
					if (nodeRem->right)
					{
						nodeRem->right->parent = prevNode;
					}
				}
			}
		}
	}

	if (flg == 0)
	{
		std::cout << "There is no such an element." << std::endl;
	}

	return 0;
}

template<typename T>
Tree<T>::template Iterator Tree<T>::Begin()
{
	Node<T>* node = _top;

	while (node->right)
	{
		node = node->right;
	}

	Iterator iter(node, node->parent);

	return iter;
}

template<typename T>
Tree<T>::template Iterator Tree<T>::End()
{
	Node<T>* node = _top->parent;
	Node<T>* prevNode = _top;

	while (prevNode->left)
	{
		prevNode = prevNode->left;
	}

	Iterator iter(node, prevNode);

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
			_initialNode = _initialNode->parent;

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
			_initialNode = _initialNode->parent;

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
	if (_initialNode != b._initialNode)
	{
		return true;
	}

	return false;
}

template<typename T>
bool Tree<T>::Iterator::operator==(const Iterator& b)
{
	if (_initialNode == b._initialNode)
	{
		return true;
	}

	return false;
}
