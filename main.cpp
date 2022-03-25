/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:37:43 by smhah             #+#    #+#             */
/*   Updated: 2022/03/25 19:01:18 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
#include <vector>
#include "iterator_traits.hpp"

int main(int ac, char **av)
{
    ft::vector<int> foo;   // three ints with a value of 100
    std::vector<int> bar;  // five ints with a value of 200

    
    // foo.swap(bar);
    foo.push_back(1);
    foo.push_back(2);
    foo.push_back(3);
    ft::vector<int>::iterator itb;
    ft::vector<int>::iterator ite;
    itb = foo.begin();
    ite = foo.begin() + 1;
    ite = foo.erase(itb, ite);
    //itb = foo.erase(itb);

    bar.push_back(1);
    bar.push_back(2);
    bar.push_back(3);
    std::vector<int>::iterator itob;
    std::vector<int>::iterator itoe;
    itob = bar.begin() + 1;
    itoe = bar.begin() + 2;
    itob = bar.erase(itob, itoe);
    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
    std::cout << '\n';
    
    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
    std::cout << '\n';

    return 0;
}