/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:45:00 by smhah             #+#    #+#             */
/*   Updated: 2022/04/20 05:39:31 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "root.hpp"

// Driver Code
int main()
{
	
	ft::map<int, int> m;
	ft::pair<int, int> planet1;
	ft::pair<int, int> planet3;
	ft::pair<int, int> planet5;
	ft::pair<int, int> planet7;
	ft::pair<int, int> planet9;
	ft::pair<int, int> planet8;
	ft::map<int, int>::iterator it;
	
	it = m.begin();

	//std::cout << "*it = " << *it << std::endl;

	planet1 = ft::make_pair(1, 1);
	planet3 = ft::make_pair(3, 2);
	planet5 = ft::make_pair(5, 3);
	planet7 = ft::make_pair(7, 4);
	planet9 = ft::make_pair(9, 5);
	planet8 = ft::make_pair(8, 6);
	//std::cout << "string is "<< planet.first << " int is " << planet.second << std::endl;
	ft::map<int, int>::Node *root = NULL;
	root = m.insert(root, planet7, root);
	root = m.insert(root, planet3, root);
	root = m.insert(root, planet9, root);
	root = m.insert(root, planet5, root);
	root = m.insert(root, planet8, root);
	root = m.deleteNode(root, planet9);
	
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
	m.preOrder(root);
	m.printTree(root, nullptr, false);
	return 0;
}

// This code is contributed by
// rathbhupendra