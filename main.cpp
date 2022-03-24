/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:37:43 by smhah             #+#    #+#             */
/*   Updated: 2022/03/23 22:31:40 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
#include <vector>
#include "iterator_traits.hpp"

int main(int ac, char **av)
{
    ft::vector<char> test;
    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);
    ft::vector<char>::iterator  it;

    std::cout << "HELLO SALAH" << std::endl;

    // it = foo.begin();
    // it = foo.insert(it, 20);
    // for(int i = 0; i < foo.size(); i++)
    //     std::cout << foo[i] << std::endl;
    // std::cout << "it point to: " << *it << std::endl;
    test.push_back('b');
    test.push_back('c');
    test.push_back('d');
    it = test.begin();
    it = test.insert(it, 'a');
    for(int i = 0; i < test.size(); i++)
        std::cout << test[i] << std::endl;
    // ft::vector<char>::iterator itob = test.begin();
    // ft::vector<char>::iterator itoe = test.end();
    // ft::vector<char>::iterator itb = test.begin();
    // ft::vector<char>::iterator ite = test.end();
    // itb =  itb + 1;
    // std::cout << test.at(0) << std::endl;
}