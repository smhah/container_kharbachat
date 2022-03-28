/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:37:43 by smhah             #+#    #+#             */
/*   Updated: 2022/03/28 01:53:03 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
#include <vector>
#include "iterator_traits.hpp"

int main(int ac, char **av)
{
    ft::Vector<int> foo;   // three ints with a value of 100
    std::vector<int> bar;  // five ints with a value of 200
    
    foo.push_back(1);
    foo.push_back(2);
    foo.push_back(3);
    foo.push_back(4);
    foo.push_back(5);
    ft::Vector<int> foo_one(3, 50);
    // int myarray [] = { 501,502,503 };
    ft::Vector<int>::iterator itb;
    // ft::Vector<int>::iterator ite;
    itb = foo.begin();
    // ite = foo.begin() + 5;
    foo.assign(foo_one.begin(), foo_one.end());
    // bar.push_back(1);
    // bar.push_back(2);
    // bar.push_back(3);
    // bar.push_back(4);
    // bar.push_back(5);
    // std::vector<int>::iterator itob;
    // std::vector<int>::iterator itoe;
    // std::vector<int> bar_one(3, 50);

    // itob = bar.end();
    // itoe = bar.begin() + 5;
    // bar.assign(bar_one.begin() + 1, bar_one.end());
    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
    std::cout << '\n';
    
    // std::cout << "bar contains:";
    // for (unsigned i=0; i<bar.size(); i++)
    // std::cout << ' ' << bar[i];
    // std::cout << '\n';
    // //while(1);
    return 0;
}