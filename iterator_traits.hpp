/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:56:53 by smhah             #+#    #+#             */
/*   Updated: 2022/03/21 20:31:15 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
namespace ft
{
	
	template <class T>
	class iterator_op
	{
		public:    
			iterator_op() {};
			
			iterator_op(iterator_op const & to_copy) {
				_iterator = to_copy._iterator;
			};
			
			iterator_op(T * pointer){
				_iterator = pointer;
			}
			
			~iterator_op(){};
			
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
			
			T   operator*(){
				return (*_iterator);  
			};
			
			iterator_op operator++(int){
				_iterator++;
				return (*this);
			};

			iterator_op operator++(){
				++_iterator;
				return (*this);
			}
			
			iterator_op operator--(int){
				_iterator--;
				return (*this);
			}

			iterator_op operator--(){
				--_iterator;
				return (*this);
			}
			T   & operator[](unsigned int index){
				return(_iterator[index]);
			}
		private:
		   T* _iterator;
	};
	
	// template <class Iterator> 
	// struct iterator_traits
	// {
	//     /* Result of subtracting one iterator from another, from Iterator. */
	//     typedef typename Iterator::difference_type       difference_type;

	//     /* Type of the element where iterator point, from Iterator. */
	//     typedef typename Iterator::value_type            value_type;

	//     /* Type of a pointer to an element where the iterator point, from Iterator. */
	//     typedef typename Iterator::pointer               pointer;

	//     /* Type of a reference where iterator point, from Iterator. */
	//     typedef typename Iterator::reference             reference;

	//     /* The iterator category from Iterator. */
	//     typedef typename Iterator::iterator_category     iterator_category;
	// };

	// template <class T> 
	// struct iterator_traits<T*>
	// {
	//     /* Result of subtracting one iterator from another. */
	//     typedef ptrdiff_t                       difference_type;

	//     /* Type of the element where iterator point. */
	//     typedef T                               value_type;

	//     /* Type of a pointer to an element where the iterator point. */
	//     typedef T*                              pointer;

	//     /* Type of a reference where iterator point. */
	//     typedef T&                              reference;

	//     /* The iterator category from Iterator. */
	//     //typedef ft::random_access_iterator_tag  iterator_category;
	// };
};