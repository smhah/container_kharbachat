/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:33:18 by smhah             #+#    #+#             */
/*   Updated: 2022/03/25 19:01:58 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "iterator_traits.hpp"
#include <stdio.h>
#include <iterator>
#include <algorithm>
#pragma once
namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef	T	value_type;
			typedef Alloc allocator_type;
			typedef size_t	size_type;
			typedef	ft::iterator_op<T> iterator;
			typedef typename	allocator_type::pointer	pointer;
			typedef typename	allocator_type::const_pointer	const_pointer;
			typedef typename	allocator_type::reference	reference;
			typedef typename	allocator_type::const_reference const_reference;
			typedef typename	std::ptrdiff_t							difference_type;
			//_________exceptions__________________
			class outOfBound : public std::exception
			{
				public:
					outOfBound() throw() {}
					virtual ~outOfBound() throw() {}
					virtual const char * what() const throw()
					{
						return ("Element out of bound\n");
					}
			};

			//_________constructors________________
			
			vector(const allocator_type & alloc= allocator_type())
			{
				std::cout << "default constructor called" << std::endl;
				_capacity = 2;
				this->_content = this->_allocator.allocate(_capacity);
				this->_size = 0;
			};
			explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
			{
				_capacity = 2;
				_content = _allocator.allocate(_capacity);
				_size = 0;
				while(n > _capacity)
					realloc_capacity();
				int i = 0;
				while(i < n)
				{
					_allocator.construct(_content + i, val);
					i++;
					_size++;
				}
			}
			~vector()
			{
				//delete [] _content;
			};
			//_________operators__________
			vector &	operator=(vector const & rhs)
			{
				std::cout << "operator = called" << std::endl;
				//_allocator.deallocate(_content, _capacity);
				// if(rhs == *this)
				// 	return *this;
				this->clear();
				_content = _allocator.allocate(rhs._capacity);
				for(int i = 0; i < rhs.size(); i++)
					_allocator.construct(_content + i, rhs._content[i]);
				_capacity = rhs._capacity;
				_size = rhs._size;
				return *this;
			}

			reference	operator[](unsigned int index)
			{
				return (_content[index]);
			}

			//_________member functions________________

			iterator erase (iterator position)
			{
				iterator save_position = position;
				iterator next;
				for(;position < end() - 1;position++)
				{
					next = position + 1;
					std::swap(*position.get_pointer(), *next.get_pointer());
				}
				pop_back();
				return (save_position);
			}
			
			iterator erase (iterator first, iterator last)
			{
				iterator save_first = first;
				size_type distance = std::distance(begin(), end());
				for(;first < end() - 1;first++)
				{
					_allocator.destroy(_content);
				}
			}

			void swap(vector & x)
			{
				pointer content = _content;
				size_type size = _size;
				size_type capacity = _capacity;

				_content = x._content;
				_size = x._size;
				_capacity = x._capacity;

				x._content = content;
				x._size = size;
				x._capacity = capacity;
			}

			void resize (size_type n, value_type val = value_type())
			{
				if(n < _size)
				{
					while(_size > n)
						pop_back();
				}
				else if (n > _capacity)
				{
					while(n > _capacity)
						realloc_capacity();
				}
				else
				{
					while(_size < n)
							push_back(val);
				}
				return ;
			}

			size_type max_size() const
			{
				return(_allocator.max_size());
			}
			
			size_type	size(void) const
			{
				return (_size);
			}
			
			reference at(unsigned int index)
			{
				if(index >= _size)
					throw std::out_of_range("vector");
				return (_content[index]);
			}
			
			const reference at(unsigned int index) const
			{
				if(index >= _size)
					throw std::out_of_range("vector");
				return (_content[index]);
			}
			
			void	realloc_capacity(void)
			{
				value_type *tmp;
				size_type old_capacity = _capacity;

				_capacity *= 2;
				tmp = _allocator.allocate(_capacity);
				for(int i = 0; i < _size; i++)
					_allocator.construct(tmp + i, _content[i]);
				_allocator.deallocate(_content, old_capacity);
				_content = tmp;
			}
			
			void	push_back(const value_type & n)
			{
				if(_size + 1 >= _capacity)
					realloc_capacity();
				_content[_size] = n;
				_size++;
			}

			void pop_back()
			{
				_allocator.destroy(_content + _size);
				//_allocator.deallocate(_content + _size, 1);
				_size--;
			}
			
			iterator	begin()
			{
				return(iterator(_content));
			}

			iterator	end()
			{
				return(iterator(_content + _size));
			}

			reference front()
			{
				return(_content[0]);
			}

			const_reference front() const
			{
				return(_content[0]);
			}

			reference back()
			{
				return (_content[_size - 1]);
			}

			const_reference back() const
			{
				return (_content[_size - 1]);
			}

			size_type capacity() const
			{
				return (_capacity);
			}
			
			void clear()
			{
				while(_size)
					pop_back();
			}

			bool empty() const
			{
				return (_size == 0);
			}

			allocator_type get_allocator() const
			{
				return (_allocator);
			}

			int	compare_pointers(pointer one, pointer two)
			{
				for(int i = 0;i < size(); i++)
				{
					if(one[i] != two[i])
						return (0);
				}
				return(1);
			}
			iterator insert (iterator position, const value_type& val)
			{
				pointer tmp;

				// size_type distance = std::distance(begin(), position);
				size_type distance = std::distance(begin(), position);
				std::cout << "distance : " << distance << std::endl;
				if(_size + 1 >= _capacity)
					realloc_capacity();
				tmp = _allocator.allocate(_capacity);
				int i = -1;
				while(++i < size())
				{
					if(compare_pointers(position.get_pointer(), _content + i))
					{
						_size++;
						int j = 0;
						while(j < i)
						{
							_allocator.construct(tmp + j, _content[j]);
							j++;
						}								
						_allocator.construct(tmp + j, val);
						j++;
						while(i < size() - 1)
						{
							_allocator.construct(tmp + j, _content[i]);
							i++;
							j++;
						}
						break;
					} 
					else if(i + 1 == size())
					{
						if(compare_pointers(position.get_pointer() - 1, _content + i))
						{
							this->push_back(val);
							_allocator.deallocate(tmp, _capacity);
							return iterator(_content + i + 1);
						}
					}
				}
				_allocator.deallocate(_content, _capacity);
				_content = tmp;
				_allocator.deallocate(tmp, _capacity);
				return (position);
			}

			void	insert (iterator position, size_type n , const value_type& val)
			{
				pointer tmp;

				if(_size + 1 >= _capacity)
					realloc_capacity();
				tmp = _allocator.allocate(_capacity);
				int i = -1;
				while(++i < size())
				{
					if(compare_pointers(position.get_pointer(), _content + i))
					{
						std::cout << "ENTERED" << std::endl;
						_size += n;
						int j = 0;
						while(j < i)
						{
							_allocator.construct(tmp + j, _content[j]);
							j++;
						}
						int c = n;
						while(c--)
						{
							_allocator.construct(tmp + j, val);
							j++;
						}
						while(i < size() - n)
						{
							_allocator.construct(tmp + j, _content[i]);
							std::cout <<"content[" << i << "] = " <<_content[i] << std::endl;
							std::cout <<"tmp[" << j << "] = " <<tmp[j] << std::endl;
							i++;
							j++;
						}
						break;
					} 
					else if(i + 1 == size())
					{
						if(compare_pointers(position.get_pointer() - 1, _content + i))
						{
							while(n--)
								this->push_back(val);
							_allocator.deallocate(tmp, _capacity);
							return ;
						}
					}
				}
				_allocator.deallocate(_content, _capacity);
				_content = tmp;
				_allocator.deallocate(tmp, _capacity);
				return ;
			}
			//_________getters________________
			
			value_type	get_content(int i) const
			{
				return(this->_content[i]);
			}
			//__________seters_________________
			
			// vector(vector const & src)
			// {
			// 	(void)src;
			// };

			// push_back(value_type content)
			// {
				
			// }
		protected:
			allocator_type	_allocator;
			//pointer			ptr;
			pointer _content;
			unsigned int	_size;
			size_type		_capacity;
	};
	// template < class T, class Alloc = std::allocator<T> > 
	// std::ostream &			operator<<( std::ostream & o, vector<T, Alloc> const & k )
	// {
	// 	std::cout << "TEST" << std::endl;
	// 	for(int i = 0;i < k.get_size();i++)
	// 	{
	// 		o << k.get_content(i) << std::endl;
	// 	}
	// }
}; // end of namespace
#endif