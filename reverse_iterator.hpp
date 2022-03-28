/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 02:30:58 by smhah             #+#    #+#             */
/*   Updated: 2022/03/28 02:38:53 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <iostream>
#include <cstddef>
#include "utils.hpp"

namespace ft 
{
	template <class Iterator>
		class iterator_traits {
			public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
		};
	template <class T>
		class iterator_traits<T*> {
			public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
		};
	
	template <class T>
		class iterator_traits<const T*> {
			public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef const T*						pointer;
			typedef const T&						reference;
			typedef std::random_access_iterator_tag	iterator_category;
		};
    
    template <class Iterator>
    class reverse_iterator
    {
        public:
				typedef 			Iterator										iterator_type;
				typedef typename	iterator_traits<Iterator>::iterator_category	iterator_category;
				typedef typename	iterator_traits<Iterator>::value_type			value_type;
				typedef typename	iterator_traits<Iterator>::difference_type		difference_type;
				typedef typename	iterator_traits<Iterator>::pointer				pointer;
				typedef typename	iterator_traits<Iterator>::reference			reference;
        
        reverse_iterator() {}
        explicit reverse_iterator(iterator_type it) : _iter(it) {}
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iter(rev_it._iter) {}
        iterator_type base() const {return _iter;}
        reference operator*() const {return *_iter;}
        
        private:
                iterator_type _iter;
    }
}
	
#endif