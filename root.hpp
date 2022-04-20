/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:44:26 by smhah             #+#    #+#             */
/*   Updated: 2022/04/20 05:35:50 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C++ program to insert a node in AVL tree
//#include<bits/stdc++.h>
#include "ft_pair.hpp"
#include "map_iterator.hpp"

namespace ft
{
	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
			> class map
	{
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<key_type,mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
	
		public:
		
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			_size = 0;
			_al = alloc;
			_kc = comp;
		}

		
		// An AVL tree node
		struct Node
		{
			value_type *content;
			Node *left;
			Node *right;
			Node *parent;
			int height;
		};
		typedef typename ft::map_iter<Node, value_type,Compare> iterator;
		Node *p;
		iterator begin()
		{
			return(iterator(p));
		}
		// A utility function to get the
		// height of the tree
		// template<class Key, class T>
		int height(Node*  N)
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
		// template<class Key, class T>
		Node* newNode(value_type content, Node* parent)
		{
			Node* node = new Node();
			// node->key = key;
			node->content = content;
			node->left = NULL;
			node->right = NULL;
			node->parent = parent;
			node->height = 1; // new node is initially
							// added at leaf
			// std::cout << "node inserted " << node->content.first << std::endl;
			// if(parent)
			// 	std::cout << "parent of the node " << node->parent->content.first << std::endl;
			return(node);
		}

		// A utility function to right
		// rotate subtree rooted with y
		// See the diagram given above.
		// template<class Key, class T>
		Node *rightRotate(Node *y)
		{
			Node *x = y->left;
			Node *T2 = x->right;

			// Perform rotation
			x->right = y;
			x->parent = y->parent;
			y->parent = x;
			if(T2)
				T2->parent = y;
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
		// template<class Key, class T>
		Node *leftRotate(Node *x)
		{
			Node *y = x->right;
			Node *T2 = y->left;

			// Perform rotation
			y->left = x;
			y->parent = x->parent;
			x->parent = y;
			//std::cout << "t2 content is " << T2->content.first << std::endl;
			if(T2)
				T2->parent = x;
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
		// template<class Key, class T>
		int getBalance(Node *N)
		{
			if (N == NULL)
				return 0;
			return height(N->left) - height(N->right);
		}

		// Recursive function to insert a key
		// in the subtree rooted with node and
		// returns the new root of the subtree.
		// template<class Key, class T>
		Node* insert(Node* node, value_type content, Node* parent)
		{
			/* 1. Perform the normal BST insertion */
			if (node == NULL)
				return(newNode(content, parent));

			// if (key < node->key)
			// 	node->left = insert(node->left, key);
			// else if (key > node->key)
			// 	node->right = insert(node->right, key);
			// else // Equal keys are not allowed in BST
			// 	return node;
			if (content < node->content)
				node->left = insert(node->left, content, node);
			else if (content > node->content)
				node->right = insert(node->right, content, node);
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

			// if (balance > 1 && content < node->left->content)
			// 	return rightRotate(node);

			// // Right Right Case

			// if (balance < -1 && content > node->right->content)
			// 	return leftRotate(node);

			// // Left Right Case

			// if (balance > 1 && content > node->left->content)
			// {	
			// 	node->left = leftRotate(node->left);
			// 	return rightRotate(node);
			// }
			// // Right Left Case

			// if (balance < -1 && content < node->right->content)
			// {
			// 	node->right = rightRotate(node->right);
			// 	return leftRotate(node);
			// }
			/* return the (unchanged) node pointer */
			return node;
		}

		// A utility function to print preorder
		// traversal of the tree.
		// The function also prints height
		// of every node
		/* Given a non-empty binary search tree,
		return the node with minimum key value
		found in that tree. Note that the entire
		tree does not need to be searched. */
		// template<class Key, class T>
		Node * minValueNode(Node* node)
		{
			Node* current = node;
		
			/* loop down to find the leftmost leaf */
			while (current->left != NULL)
				current = current->left;
		
			return current;
		}
		
		// Recursive function to delete a node
		// with given key from subtree with
		// given root. It returns root of the
		// modified subtree.
		// template<class Key, class T>
		Node* deleteNode(Node* root, value_type content)
		{
			
			// STEP 1: PERFORM STANDARD BST DELETE
			if (root == NULL)
				return root;
		
			// If the key to be deleted is smaller
			// than the root's key, then it lies
			// in left subtree
			if ( content < root->content )
				root->left = deleteNode(root->left, content);
		
			// If the content to be deleted is greater
			// than the root's content, then it lies
			// in right subtree
			else if( content > root->content )
				root->right = deleteNode(root->right, content);
		
			// if content is same as root's content, then
			// This is the node to be deleted
			else
			{
				// node with only one child or no child
				if( (root->left == NULL) ||
					(root->right == NULL) )
				{
					Node *temp = root->left ? root->left : root->right;
		
					// No child case
					if (temp == NULL)
					{
						temp = root;
						std::cout << "node deleted " << root->content.first << std::endl;
						root = NULL;
					}
					else // One child case
					{ 
						//*root = *temp;
						//std::swap(*root, *temp);
						root->content = temp->content;
						if(temp == root->left)
							root->left = NULL;
							//deleteNode(root->left, temp->content);
						else
							root->right = NULL;
							//deleteNode(root->right, temp->content);
						std::cout << "1parent is " << root->parent->content.first << std::endl;
					} // Copy the contents of
								// the non-empty child
					free(temp);
					temp = NULL;
				}
				else
				{
					// node with two children: Get the inorder
					// successor (smallest in the right subtree)
					Node* temp = minValueNode(root->right);
		
					// Copy the inorder successor's
					// data to this node
					root->content = temp->content;
		
					// Delete the inorder successor
					root->right = deleteNode(root->right,
											temp->content);
				}
			}
		
			// If the tree had only one node
			// then return
			if (root == NULL)
			return root;
		
			// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
			root->height = 1 + max(height(root->left),
								height(root->right));
		
			// STEP 3: GET THE BALANCE FACTOR OF
			// THIS NODE (to check whether this
			// node became unbalanced)
			int balance = getBalance(root);
		
			// If this node becomes unbalanced,
			// then there are 4 cases
		
			// Left Left Case
			if (balance > 1 &&
				getBalance(root->left) >= 0)
				return rightRotate(root);
		
			// Left Right Case
			if (balance > 1 &&
				getBalance(root->left) < 0)
			{
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		
			// Right Right Case
			if (balance < -1 &&
				getBalance(root->right) <= 0)
				return leftRotate(root);
		
			// Right Left Case
			if (balance < -1 &&
				getBalance(root->right) > 0)
			{
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		
			return root;
		}

		struct Trunk
		{
			Trunk *prev;
			std::string str;
		
			Trunk(Trunk *prev, std::string str)
			{
				this->prev = prev;
				this->str = str;
			}
		};
		
		// Helper function to print branches of the binary tree
		void showTrunks(Trunk *p)
		{
			if (p == nullptr) {
				return;
			}
		
			showTrunks(p->prev);
			std::cout << p->str;
		}

		// template<class Key, class T>
		void printTree(Node* root, Trunk *prev, bool isLeft)
		{
			if (root == nullptr) {
				return;
			}
		
			std::string prev_str = "    ";
			Trunk *trunk = new Trunk(prev, prev_str);
		
			printTree(root->right, trunk, true);
		
			if (!prev) {
				trunk->str = "———";
			}
			else if (isLeft)
			{
				trunk->str = ".———";
				prev_str = "   |";
			}
			else {
				trunk->str = "`———";
				prev->str = prev_str;
			}
		
			showTrunks(trunk);
			std::cout << " " << root->content->first << std::endl;
		
			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   |";
		
			printTree(root->left, trunk, false);
		}

		// template<class Key, class T>
		void preOrder(Node *root)
		{
			if(root != NULL)
			{
				std::cout <<"key is " << root->content->first << std::endl;
				if(root->left)
					std::cout << "left child is " << root->left->content->first << std::endl;
				if (root->right)
					std::cout << "right child is " << root->right->content->first << std::endl;
				if(root->parent)
					std::cout <<"parent is " << root->parent->content->first <<std::endl;
				preOrder(root->left);
				preOrder(root->right);
			}
		}
		private:
            size_t  _size;
            Alloc   _al;
            key_compare _kc;
	};
}



