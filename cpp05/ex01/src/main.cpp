/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/12/17 18:09:29 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include"../include/Form.hpp"

void    printErrorMessage(const std::exception& e)
{
        std::cerr << "Error: " << e.what() << std::endl;    
}

int	main(void)
{
    try 
    {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Mike", 5);
        Form f1("f1",2, 3);

        std::cout << f1;
        std::cout << b1;
        std::cout << b2;


        b2.signForm(f1);
        b1.signForm(f1);
        b1.signForm(f1);
    }
    catch (const std::exception& e)  {printErrorMessage(e);}

	return (0);
}




