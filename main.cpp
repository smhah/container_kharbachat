/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:37:43 by smhah             #+#    #+#             */
/*   Updated: 2022/03/24 20:11:35 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
#include <vector>
#include "iterator_traits.hpp"

int main(int ac, char **av)
{
    ft::vector<char> test;
    std::vector<char> testo;
    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);
    std::vector<int>::iterator  ito; 
    ft::vector<char>::iterator  it;

    std::cout << "HELLO SALAH" << std::endl;
    ito = foo.begin();
    foo.insert(it, 2, 150);
    for(int i = 0;i < foo.size();i++)
        std::cout << foo[i] << std::endl;
    
}