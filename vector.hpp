/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:33:18 by smhah             #+#    #+#             */
/*   Updated: 2022/03/23 22:40:06 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iterator_traits.hpp"
//#include <iterator>


namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef	T	value_type;
			typedef Alloc allocator_type;
			typedef size_t	size_type;
			typedef ft::iterator_op<T> iterator;
			typedef typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference const_reference;
			
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
				//std::cout << "alloc is :" << alloc << std::endl;
				//this->_content = this->allocator.allocate(100);
				//this->_content = NULL;
				this->_capacity = 2;
				this->_content = this->_allocator.allocate(sizeof(value_type) * 2);
				//this->_allocator = nullptr;
				this->_size = 0;
				//this->_content = new value_type[100];
				//this->_size = 100;
			};
			explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
			{
				std::cout << "second default constructor called" << std::endl;
				this->_size = n;
				this->_content = this->_allocator.allocate(sizeof(value_type) * (n + 1));
				for (int i = 0; i < n;i++)
				{
					this->_content[i] = val;
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
				vector tmp;

				if(_size + 1 >= _capacity)
					realloc_capacity();
				tmp = *this;
				int i = -1;
				while(++i < size())
				{
					if(compare_pointers(position.get_pointer(), _content + i))
					{
						_size++;
						std::cout << "ENTERED" << std::endl;
						int j = 0;
						while(j < i)
						{
							tmp._allocator.construct(tmp._content + j, _content[i]);
							j++;
						}				
						//inserting
						tmp._allocator.construct(tmp._content + j, val);
						j++;
						while(i < size())
						{
							std::cout << "content[i] = " << _content[i] << std::endl;
							tmp._allocator.construct(tmp._content + j, _content[i]);
							std::cout << "tmp.content[j] = " << tmp._content[j] << std::endl;
							i++;
							j++;
						}
						break;
					}
				}
				*this = tmp;
				tmp.clear();
				return (position);
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
