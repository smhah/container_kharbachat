/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:56:53 by smhah             #+#    #+#             */
/*   Updated: 2022/03/29 03:22:31 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "utils/utils.hpp"
#include "iterator_traits.hpp"

namespace ft
{
	
	template <class T>
	class iterator_op : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef typename iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename iterator<std::random_access_iterator_tag, T>::reference			reference;
			typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
	
			iterator_op() {};
			
			iterator_op(iterator_op const & to_copy) {
				_iterator = to_copy._iterator;
			};
			
			iterator_op(T * pointer){
				_iterator = pointer;
			}
			
			~iterator_op(){};
			
			operator iterator_op<const T> () const { return iterator_op<const T>(_iterator); }
			
			iterator_op & operator=(iterator_op const & rhs){
				_iterator = rhs._iterator;
				return *this;
			};
			
			iterator_op operator+(int n){
				return(iterator_op(_iterator + n));
			}

			iterator_op operator+=(int n){
				return(iterator_op(_iterator += n));
			}
			
			iterator_op operator-(int n){
				return(iterator_op(_iterator - n));
			}

			iterator_op operator-=(int n){
				return(iterator_op(_iterator -= n));
			}
			
			int operator-(const iterator_op & to_subtract){
				return(_iterator - to_subtract._iterator);
			}

			bool operator==(const iterator_op & to_compare) const{
				return (_iterator == to_compare._iterator);
			};

			bool operator!=(const iterator_op & to_compare) const{
				return (_iterator != to_compare._iterator);
			};
			
			bool operator<=(const iterator_op & to_compare) const{
				return (_iterator <= to_compare._iterator);
			};
			
			bool operator<(const iterator_op & to_compare) const{
				return (_iterator < to_compare._iterator);
			};
			
			bool operator>=(const iterator_op & to_compare) const{
				return (_iterator >= to_compare._iterator);
			};
			
			bool operator>(const iterator_op & to_compare) const{
				return (_iterator > to_compare._iterator);
			};
			
			reference operator*(){
				return (*_iterator);  
			};
			
			iterator_op operator++(int){
				iterator_op tmp = *this;
				_iterator += 1;
				return (tmp);
			};

			iterator_op operator++(){
				++_iterator;
				return (*this);
			}
			
			iterator_op operator--(int){
				iterator_op tmp = *this;
				_iterator -= 1;
				return (tmp);
			}

			iterator_op operator--(){
				--_iterator;
				return (*this);
			}
			
			reference operator[](unsigned int index){
				return(_iterator[index]);
			}
			
			pointer	operator->() {
				return &operator*();
			}

			pointer get_pointer(){
				return _iterator;
			}
		private:
		   pointer _iterator;
	};

	template <class T>
	iterator_op<T> operator+(int n, iterator_op<T> & it){
		return(iterator_op<T>(it + n));	
	}
};