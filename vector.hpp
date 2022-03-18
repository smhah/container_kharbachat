/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:33:18 by smhah             #+#    #+#             */
/*   Updated: 2022/03/18 20:40:19 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < class T, class Alloc = std::allocator<T> > 
class vector
{
	public:
		typedef	T	value_type;
		typedef Alloc allocator_type;
		typedef size_t	size_type;
		
		//_________operators overload__________
		vector &	operator=(vector const & rhs)
		{
			if(this != &rhs)
			{
				if(this->_size > 0 && this->_content != NULL)
					delete [] this->_content;
				this->_content = this->_allocator.allocate(sizeof(value_type) * (rhs._size + 1));
				int i = 0;
				while(i < rhs._size)
				{
					this->_allocator.construct(this->_content[i]);
					i++;
				}
				this->_content[i] = NULL;
			}
		}
		//_________constructors________________
		
		vector(const allocator_type & alloc= allocator_type())
		{
			std::cout << "default constructor called" << std::endl;
			//std::cout << "alloc is :" << alloc << std::endl;
			//this->_content = this->allocator.allocate(100);
			this->_content = NULL;
			//this->_allocator = nullptr;
			this->_size = 0;
			//this->_content = new value_type[100];
			//this->_size = 100;
		};
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
		{
			this->_size = n;
			this->_content = this->_allocator.allocate(sizeof(value_type) * (n + 1));
			for (int i = 0; i < n;i++)
			{
				this->_content[i] = val;
			}
		}
		//_________member functions________________
		void	push_back(value_type n)
		{
			//this->_allocator.allocate(5 * sizeof(int));
			int i = 0;
			while(i < _size)
				i++;
			this->_content = new value_type[5];
			this->_content[i] = n;
			this->_size++;
			this->_content[i + 1] = NULL;
		}
		//_________geters________________
		int		get_size(void) const
		{
			return (this->_size);
		}
		value_type	get_content(int i) const
		{
			return(this->_content[i]);
		}
		//__________seters_________________
		
		vector(vector const & src)
		{
			(void)src;
		};

		// push_back(value_type content)
		// {
			
		// }
		
		~vector()
		{
			delete [] _content;
		};
	protected:
		allocator_type	_allocator;
		value_type		*_content;
		unsigned int	_size;
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