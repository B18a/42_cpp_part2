/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:03:50 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/24 09:48:11 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

template<typename T>
void	printData(T data)
{
	std::cout << data << std::endl;
}

template <typename T, typename Func>
void	iter(T* address, int len, Func func)
{
	int i = 0;
	while(i < len)
	{
		func(address[i]);
		i++;
	}
}