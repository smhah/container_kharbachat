/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:33:09 by smhah             #+#    #+#             */
/*   Updated: 2022/03/27 22:12:41 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <memory>
#include <algorithm>
#pragma once

namespace ft
{
    template <	class Category, class T, class Distance = std::ptrdiff_t,
				class Pointer = T*, class Reference = T&>
		struct iterator {
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
		};

    template <typename T> struct is_integral {	static const bool value = false;	};
	template<> struct is_integral<bool> {	static const bool value = true;	};
	template<> struct is_integral<char> {	static const bool value = true;	};
	template<> struct is_integral<char16_t> {	static const bool value = true;	};
	template<> struct is_integral<char32_t> {	static const bool value = true;	};
	template<> struct is_integral<wchar_t> {	static const bool value = true;	};
	template<> struct is_integral<signed char> {	static const bool value = true;	};
	template<> struct is_integral<short int> {	static const bool value = true;	};
	template<> struct is_integral<int> {	static const bool value = true;	};
	template<> struct is_integral<long long int> {	static const bool value = true;	};
	template<> struct is_integral<unsigned char> {	static const bool value = true;	};
	template<> struct is_integral<unsigned short int> {	static const bool value = true;	};
	template<> struct is_integral<unsigned int> {	static const bool value = true;	};
	template<> struct is_integral<unsigned long int> {	static const bool value = true;	};
	template<> struct is_integral<unsigned long long int> {	static const bool value = true;	};

	template <bool cond, class T = void> struct enable_if {};

	template <class T> struct enable_if<true, T> {	typedef T type;	};
};

#endif
