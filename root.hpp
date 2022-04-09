/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:44:26 by smhah             #+#    #+#             */
/*   Updated: 2022/04/05 02:22:32 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C++ program to insert a node in AVL tree
//#include<bits/stdc++.h>
#include "ft_pair.hpp"

// An AVL tree node
template<class Key, class T>
class Node
{
	public:
	ft::pair<Key, T> content;
	//int key;
	Node *left;
	Node *right;
	int height;
};

// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get the
// height of the tree
template<class Key, class T>
int height(Node<Key, T>*  N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
template<class Key, class T>
Node<Key, T>* newNode(ft::pair<Key, T> content)
{
	Node<Key, T>* node = new Node<Key, T>();
	// node->key = key;
	node->content = content;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					// added at leaf
	return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
template<class Key, class T>
Node<Key, T> *rightRotate(Node<Key, T> *y)
{
	Node<Key, T> *x = y->left;
	Node<Key, T> *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
template<class Key, class T>
Node<Key, T> *leftRotate(Node<Key, T> *x)
{
	Node<Key, T> *y = x->right;
	Node<Key, T> *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
template<class Key, class T>
int getBalance(Node<Key, T> *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
template<class Key, class T>
Node<Key, T>* insert(Node<Key, T>* node, ft::pair<Key, T> content)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(content));

	// if (key < node->key)
	// 	node->left = insert(node->left, key);
	// else if (key > node->key)
	// 	node->right = insert(node->right, key);
	// else // Equal keys are not allowed in BST
	// 	return node;

	if (content < node->content)
		node->left = insert(node->left, content);
	else if (content > node->content)
		node->right = insert(node->right, content);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	// if (balance > 1 && key < node->left->key)
	// 	return rightRotate(node);

	if (balance > 1 && content < node->left->content)
		return rightRotate(node);

	// Right Right Case
	// if (balance < -1 && key > node->right->key)
	// 	return leftRotate(node);

	if (balance > 1 && content < node->left->content)
		return rightRotate(node);

	// Left Right Case
	// if (balance > 1 && key > node->left->key)
	// {
	// 	node->left = leftRotate(node->left);
	// 	return rightRotate(node);
	// }

	if (balance > 1 && content > node->left->content)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	// Right Left Case
	// if (balance < -1 && key < node->right->key)
	// {
	// 	node->right = rightRotate(node->right);
	// 	return leftRotate(node);
	// }

	if (balance < -1 && content < node->right->content)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}


	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
template<class Key, class T>
void preOrder(Node<Key, T> *root)
{
	if(root != NULL)
	{
		std::cout <<"key is " << root->content.first << " value is " << root->content.second << std::endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

