/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 07:47:27 by smhah             #+#    #+#             */
/*   Updated: 2022/04/20 05:20:47 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterator.hpp"

namespace ft
{
    template<class Node, class T, class comp>
    
    class map_iter : public ft::iterator<std::bidirectional_iterator_tag, T>
    {
        private:
            Node * _p;

        public:
            map_iter(){};
            map_iter(Node *p)
            {
                _p = p;
            }
            map_iter(const map_iter & copy){*this = copy; }
            map_iter & operator=(const map_iter & rhs)
            {
                _p = rhs._p;
                return *this;
            }
            ~map_iter(){};
            T* operator->() const{ return (_p->content);}
            //T& operator*() const{ return (*_p->content);}

           
    };
    
} // namespace ft
