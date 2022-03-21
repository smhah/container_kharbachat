/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:37:43 by smhah             #+#    #+#             */
/*   Updated: 2022/03/21 20:31:37 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
#include <vector>
#include "iterator_traits.hpp"

int main(int ac, char **av)
{
    ft::vector<char> test;

    std::cout << "HELLO SaLAH" << std::endl;
    test.push_back('A');
    test.push_back('c');
    test.push_back('j');
    // std::cout << "get_size() is : " << test.get_size() << std::endl;
    // for (int i = 0;i < test.get_size();i++)
    // {
    //     std::cout << test[i] << std::endl;
    //     //std::cout << test.get_content(i) << std::endl;
    // }
    // while(1);
    ft::vector<char>::iterator itob = test.begin();
    ft::vector<char>::iterator itoe = test.end();
    //ft::random_access_iterator<char> iterator = test.begin();
    ft::vector<char>::iterator itb = test.begin();
    ft::vector<char>::iterator ite = test.end();

    // std::cout << "substract : " << itob - itoe << std::endl;
    // std::cout << "substract : " << itb - ite << std::endl;
    itb += 1;
    itb -= 1;
    itb =  1 + itb;
    // itb += 1;
    // itb = itb - 1;
    // itb = itb - 1;
    std::cout << itb[0] << std::endl;
    //std::cout << it - it2 << std::endl;
    //std::cout << test.get_content(0) << std::endl;
}