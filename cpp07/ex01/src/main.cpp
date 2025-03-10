/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:03:57 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/24 09:28:10 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Template.hpp"
#include<iostream>

int main(void)
{
	int arr[5] = {5,4,3,1,8};
	double darr[4] = {1.1,3.3,2.2,9.9};
	std::string strArray[3] = {"apple", "banana", "cherry"};

	std::cout << "Array of INT" << std::endl;
	iter(arr, 5, printData<int>);
	std::cout << "\nArray of DOUBLE" << std::endl;
	iter(darr, sizeof(darr) / sizeof(darr[0]), printData<double>);
	std::cout << "\nArray of STRING" << std::endl;
	iter(strArray, sizeof(strArray) / sizeof(strArray[0]), printData<std::string>);
}