/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:21:41 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/25 11:06:04 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../include/easyfind.hpp"
#include <array>
#include <stdexcept>
#include <iostream>


int main(void)
{
    std::array<int, 3> test = {1,2,3};
    
    try
    {
        easyfind(test, 5);
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}