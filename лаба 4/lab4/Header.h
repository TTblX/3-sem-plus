#pragma once
#include <iostream>

using namespace std;

template<class T>
class Node
{
private:
	T data;
	Node* left;
	Node* right;
public:
    Node() {
        this->left = this->right = NULL;
    }

    Node(T data) {
        this->data = data;
        this->left = this->right = NULL;
    }

	Node* CreateNode(T data)
	{
		this->data = data;
		this->left = this->right = NULL;
		return this;
	}

	// Function to insert element in binary tree
	Node* InsertNode(T data)
	{
		// If the tree is empty, assign new node address to root
		if (this == nullptr) {
			return CreateNode(data);
		}

		if (this->data == data)
		{
			cout << "Error : can't be two nodes with same data" << endl;
			return this;
		}

		Node* tmp = this;

		if (tmp->data > data)
		{
            if (tmp->left == nullptr)
            {
                tmp->left = new Node<T>(data);
            }
            else
            {
                tmp->left->InsertNode(data);
            }			
		}
		else
		{
            if (tmp->right == nullptr)
            {
                tmp->right = new Node<T>(data);
            }
            else
            {
                tmp->right->InsertNode(data);
            }			
		}

	}

    Node* deleteNode(T key)
    {
        // Base case
        if (this == NULL)
            return this;

        // Recursive calls for ancestors of
        // node to be deleted
        if (this->data > key) {
            this->left = this->left->deleteNode(key);
            return this;
        }
        else if (this->data < key) {
            this->right = this->right->deleteNode(key);
            return this;
        }

        // We reach here when root is the node
        // to be deleted.

        // If one of the children is empty
        if (this->left == NULL) {
            Node* temp = this->right;
            delete this;
            return temp;
        }
        else if (this->right == NULL) {
            Node* temp = this->left;
            delete this;
            return temp;
        }

        // If both children exist
        else {

            Node* succParent = this;

            // Find successor
            Node* succ = this->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            // Delete successor.  Since successor
            // is always left child of its parent
            // we can safely make successor's right
            // right child as left of its parent.
            // If there is no succ, then assign
            // succ->right to succParent->right
            if (succParent != this)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            // Copy Successor Data to root
            this->data = succ->data;

            // Delete Successor and return root
            delete succ;
            return this;
        }
    }

    void printBT(const string& prefix, const Node* node, bool isLeft)
    {
        if (node != nullptr)
        {
            cout << prefix;

            cout << (isLeft ? "|---" : "'---");

            // print the value of the node
            cout << node->data << std::endl;

            // enter the next tree level - left and right branch
            printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
            printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
        }
    }

    void printBT(const Node* node)
    {
        printBT("", node, false);
    }

    Node& operator++() {
        this->data = this->right->data;
        this->left = this->right->left;
        this->right = this->right->right;
        
        return *this;
    }


    Node& operator--() {
        this->data = this->left->data;
        this->right = this->left->right;
        this->left = this->left->left;
        
        return *this;
    }
};

