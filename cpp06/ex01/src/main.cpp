/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:40:54 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 09:40:57 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Serializer.hpp"

struct Data;

int main(void)
{
	// constructors are missing!!!!!!!
	// constructors are missing!!!!!!!
	// constructors are missing!!!!!!!
	// constructors are missing!!!!!!!
	// constructors are missing!!!!!!!
	// constructors are missing!!!!!!!
	// constructors are missing!!!!!!!
	// constructors are missing!!!!!!!

	Data *data;
	data = new Data;

	data->number = 1;
	data->name = "test";

	uintptr_t ptr = Serializer::serialize(data);

	Data* restored_ptr = Serializer::deserialize(ptr);

	std::cout << "before serialization	" << data << std::endl;
	std::cout << "representation as int	" << ptr << std::endl;
	std::cout << "after serialization	" << restored_ptr << std::endl;
	
	return 0;
}

