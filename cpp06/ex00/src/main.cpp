/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:09 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 09:39:12 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/ScalarConverter.hpp"

int main(int argc, char** argv)
{

	(void)argc;
	if(argc == 2)
		ScalarConverter::convert(argv[1]);
	return 0;
}

