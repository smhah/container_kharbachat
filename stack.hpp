/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:52:48 by smhah             #+#    #+#             */
/*   Updated: 2022/03/29 22:14:33 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include <algorithm>
#pragma once
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Stack
	{
		public:
		
			typedef	typename Container::value_type		value_type;
			typedef	Container					container_type;
			typedef	typename Container::size_type		size_type;
		
			explicit Stack (const container_type& ctnr = container_type()) : c(ctnr)
			{
			}

			bool empty() const
			{
				return(c.empty());
			}
		
			size_type size() const
			{
				return(c.size());
			}
			
			value_type& top()
			{
				return(c.back());
			}

			const value_type& top() const
			{
				return(c.back());
			}
			
			void push (const value_type& val)
			{
				c.push_back(val);
			}
			
			void pop()
			{
				c.pop_back();
			}
			
			template <class Type, class C>
			friend bool operator== (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs);
			template <class Type, class C>
				friend bool operator!= (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs);
			template <class Type, class C>
				friend bool operator<  (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs);
			template <class Type, class C>
				friend bool operator<= (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs);
			template <class Type, class C>
				friend bool operator>  (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs);
			template <class Type, class C>
				friend bool operator>= (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs);
		protected:
			container_type c;
	};

	template <class Type, class C>
		bool operator== (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs) {	return lhs.c == rhs.c;	}
	template <class Type, class C>
		bool operator!= (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs) {	return lhs.c != rhs.c;	}
	template <class Type, class C>
		bool operator< (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs) {	return lhs.c < rhs.c;	}
	template <class Type, class C>
		bool operator<= (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs) {	return lhs.c <= rhs.c;	}
	template <class Type, class C>
		bool operator> (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs) {	return lhs.c > rhs.c;	}
	template <class Type, class C>
		bool operator>= (const Stack<Type,C>& lhs, const Stack<Type,C>& rhs) {	return lhs.c >= rhs.c;	}
}

#endif