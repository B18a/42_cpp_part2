/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:18:30 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/25 11:00:09 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <algorithm>
#include <array>
#include <iostream>
// #include <iterator>
#include <stdexcept>


class ValueNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Value not found in the container";
    }
};


// begin()  Returns an iterator to the first element of the array.
// back()   Returns a reference to the last element in the container.
// end()    Returns an iterator to the element following the last element of the array.


template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ValueNotFoundException();
    return it;
	
}

// template <typename T>
// typename T::const_iterator easyfind(const T& container, int value)
// {
//     typename T::const_iterator it = std::find(container.begin(), container.end(), value);
//     if (it == container.end())
//         throw ValueNotFoundException();
//     return it;
	
// }

