/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:45:00 by smhah             #+#    #+#             */
/*   Updated: 2022/04/05 02:21:25 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "root.hpp"

// Driver Code
int main()
{
	ft::pair<std::string, int> planeta;
	ft::pair<std::string, int> planetb;
	ft::pair<std::string, int> planetc;
	ft::pair<std::string, int> planetd;

	planeta = ft::make_pair("strina", 1);
	planetb = ft::make_pair("strinb", 2);
	planetc = ft::make_pair("strinc", 3);
	planetd = ft::make_pair("strind", 4);
	// std::cout << "string is "<< planet.first << " int is " << planet.second << std::endl;
	Node<std::string, int> *root = NULL;
	root = insert(root, planetc);
	root = insert(root, planetd);
	root = insert(root, planeta);
	root = insert(root, planetb);
	// Node *root = NULL;
	
	// /* Constructing tree given in
	// the above figure */
	// root = insert(root, 10);
	// root = insert(root, 20);
	// root = insert(root, 30);
	// root = insert(root, 40);
	// root = insert(root, 50);
	// root = insert(root, 25);
	// root = insert(root, 26);
	// /* The constructed AVL Tree would be
	// 			30
	// 		/ \
	// 		20 40
	// 		/ \ \
	// 	10 25 50
	// */
	// std::cout << "Preorder traversal of the "
	// 		"constructed AVL tree is \n";
	preOrder(root);
	
	return 0;
}

// This code is contributed by
// rathbhupendra