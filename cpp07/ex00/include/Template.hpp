/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:58:28 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/23 16:58:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// template: This keyword is used to define a function or class template.
// <typename T>: This specifies that T is a placeholder for a data type.
// typename indicates that T will represent a type (like int, float, std::string, etc.). 

template  <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
} 
 
template  <typename T>
T min(T a, T b)
{
	if(a < b)
		return a;
	else
		return b;
} 
 
template  <typename T>
T max(T a, T b)
{
	if(a > b)
		return a;
	else
		return b;
} 