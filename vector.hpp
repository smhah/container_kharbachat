/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:33:18 by smhah             #+#    #+#             */
/*   Updated: 2022/03/29 21:54:06 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "iterator.hpp"
#include <algorithm>
#pragma once

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class Vector
	{
		public:
			typedef	T	value_type;
			typedef Alloc allocator_type;
			typedef size_t	size_type;
			typedef	ft::iterator_op<T> iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef	ft::iterator_op<const value_type>			const_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
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
			
			Vector(const allocator_type & alloc= allocator_type()) : _allocator(alloc)
			{
				_capacity = 0;
				this->_content = this->_allocator.allocate(_capacity);
				this->_size = 0;
			};
			
			// explicit Vector (size_type n, const value_type& val = value_type(),
			// 		const allocator_type& alloc = allocator_type()) : _allocator(alloc)
			// {
			// 	_capacity = 2;
			// 	_content = _allocator.allocate(_capacity);
			// 	_size = 0;
			// 	while(n > _capacity)
			// 		realloc_capacity();
			// 	size_type i = 0;
			// 	while(i < n)
			// 	{
			// 		_allocator.construct(_content + i, val);
			// 		i++;
			// 		_size++;
			// 	}
			// }
			explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(n),  _capacity(n)
			{
				if (n)
					_content = _allocator.allocate(n);
				for (size_t i = 0; i < _size; i++)
					_allocator.construct(&_content[i], val);
			}
			
			Vector 			(const Vector& x): _size(0), _capacity(0)
			{
				if (!x.size())
				{
					return	;
				}
				_capacity = x.size();
				_content = _allocator.allocate(_capacity);
				*this = x;
			}

			template <class InputIterator>
         	Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
			 	typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator()) : _allocator(alloc)
			{
				difference_type n;
				n = std::distance(first, last);
				if(n < 0)
					n = n * (-1);
				_capacity = n;
				 _size = n;
				if (n)
					_content = _allocator.allocate(n);
				for (difference_type j = 0; j < n && first != last; ++j, ++first)
					_allocator.construct(&_content[j], *first);
			 }
			
			~Vector()
			{
				//delete [] _content;
			};
			//_________operators__________
			Vector &	operator=(Vector const & rhs)
			{
				this->clear();
				_content = _allocator.allocate(rhs._capacity);
				for(size_type i = 0; i < rhs.size(); i++)
					_allocator.construct(_content + i, rhs._content[i]);
				_capacity = rhs._capacity;
				_size = rhs._size;
				return *this;
			}

			reference operator[] (size_type n)
			{
				return (_content[n]);
			}

			const_reference operator[] (size_type n) const
			{
				return(_content[n]);
			}

			//_________member functions________________

			void reserve (size_type n)
			{
				if (n > max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
				if(n > _capacity)
					realloc_capacity(n);
				return ;
			}
			
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
				size_type	positionIndex = std::distance(begin(), first);
				size_type	n = std::distance(first, last);
				for (size_type i = positionIndex; i < _size - n; i++)
				{
					_content[i] = _content[i + n];
				}
				_size -= n;
				return (iterator(_content + positionIndex));
			}

			void swap(Vector & x)
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
					_size = n;
				}
				if (n > _capacity)
				{
					realloc_capacity(n);
				}
				while(_size < n)
							push_back(val);
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
			
			void	realloc_capacity(size_type n = 0)
			{
				if (n > max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
				
				if (!_capacity)
				{
					_capacity = n ? n : 1;
					_content = _allocator.allocate(_capacity);
					return ;
				}

				pointer		tmp = _content;
				size_type	cap = _capacity;

				_capacity = n ? n : _capacity * 2;

				_content = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_content + i, tmp[i]);

				_allocator.deallocate(tmp, cap);
			}
			
			void push_back (const value_type& val)
			{
				if(_size + 1 > _capacity)
					realloc_capacity();
				_size++;
				_allocator.construct(_content + _size - 1, val);
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

			const_iterator begin () const
			{
				return (const_iterator(_content));
			} 
			
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			
			const_reverse_iterator rbegin() const
			{
				return(const_reverse_iterator(end()));
			}
			
			iterator	end()
			{
				return(iterator(_content + _size));
			}

			const_iterator	end() const
			{
				return(const_iterator(_content + _size));
			}
			
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
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

			void assign (size_type n, const value_type& val)
			{
				clear();
				insert(begin(), n, val);
			}
			
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_type dist = std::distance(begin(), position);
				push_back(val);
				iterator last = end() - 1;
				position = begin() + dist;
				for(;position != last ;position++)
				{
					std::swap(*position.get_pointer(), *last.get_pointer());
				}
				return begin() + dist;
			}
			
			void	insert (iterator position, size_type n , const value_type& val)
			{
				difference_type	positionIndex = std::distance(begin(), position);
				if(_size + n > _capacity)
				{
					if (n > _size)
						reserve(_size + n);
					else
						reserve(_capacity * 2);
				}
				for (difference_type i = _size - 1; i >= positionIndex; i--)
					_allocator.construct(&_content[i + n], _content[i]);
				for (size_t i = 0; i < n; i++)
					_allocator.construct(&_content[positionIndex + i], val);
				_size += n;
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{
				difference_type	positionIndex = std::distance(begin(), position);
				size_t n = std::distance(first, last);
				if(_size + n > _capacity)
				{
					if (n > _size)
						reserve(_size + n);
					else
						reserve(_capacity * 2);
				}
				for (difference_type i = _size - 1; i >= positionIndex; i--)
					_allocator.construct(&_content[i + n], _content[i]);
				for (size_type i = 0; i < n; i++)
				{
					_allocator.construct(&_content[positionIndex + i], *first);
					first++;
				}
				_size += n;
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
		private:
			allocator_type	_allocator;
			pointer _content;
			size_type	_size;
			size_type		_capacity;
	};
	template <class T, class Alloc>
		bool	operator== (const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
	template <class T, class Alloc>
		bool	operator!= (const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return true;
			return !operator==(lhs, rhs);
		}
	template <class T, class Alloc>
  		bool	operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <class T, class Alloc>
  		bool	operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			return !operator<(rhs, lhs);
		}
	template <class T, class Alloc>
  		bool	operator> (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			return operator<(rhs, lhs);
		}
	template <class T, class Alloc>
  		bool	operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			return !operator<(lhs, rhs);
		}
	
	/*	swap	*/

	template <class T, class Alloc>
  		void	swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y) {	x.swap(y);	}
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