/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:33:18 by smhah             #+#    #+#             */
/*   Updated: 2022/03/21 19:20:13 by smhah            ###   ########.fr       */
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
			//_________operators__________
			vector &	operator=(vector const & rhs)
			{
				std::cout << "operator = called" << std::endl;
				if(this != &rhs)
				{
					if(this->_size > 0 && this->_content != NULL)
						delete [] this->_content;
					this->_content = this->_allocator.allocate(sizeof(value_type) * (rhs._size + 1));
					int i = 0;
					while(i < rhs._size)
					{
						this->_content[i] = rhs._content[i];
						i++;
					}
				}
				return *this;
			}

			value_type	& operator[](unsigned int index)
			{
				if(index >= 0)
				{
					if(index >= _size)
					{
						throw(outOfBound());
					}
					else
					{
						return (_content[index]);
					}
				}
				else
					throw(outOfBound());
				return (_content[index]);
			}
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
			//_________member functions________________
			void	realloc_capacity(void)
			{
				value_type *tmp;

				size_t old_capacity = _capacity;

				_capacity *= 2;
				tmp = _allocator.allocate(_capacity);
				for(int i = 0; i < _size; i++)
				{
					tmp[i] = _content[i];
					_allocator.construct(tmp + i, _content[i]);
				}
				_allocator.deallocate(_content, old_capacity);
				_content = tmp;
				// i don't understand why this line not affecting any memory leaks//delete [] tmp;
			}
			
			void	push_back(const value_type & n)
			{
			
				int i = 0;
				while(i < _size)
					i++;
				if(_size + 1 >= _capacity)
				{
					realloc_capacity();
				}
				_content[i] = n;
				_size++;
			}

			iterator	begin()
			{
				return(iterator(_content));
			}

			iterator	end()
			{
				return(iterator(_content + _size - 1));
			}
			//_________getters________________
			int		get_size(void) const
			{
				return (this->_size);
			}
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
