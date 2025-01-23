/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:41:01 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/23 10:37:56 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Serializer.hpp"

/****************************************/
/*		Constructor / Destructor		*/
/****************************************/

Serializer::Serializer(void){}
Serializer::~Serializer(void){}
Serializer::Serializer(const Serializer& other){(void)other;}

/****************************************/
/*		Copy Assignment Operator		*/
/****************************************/

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;	
}

/****************************************/
/*			Member Functions			*/
/****************************************/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}


// uintptr_t
// is an unsigned integer type that is guaranteed to be large enough
// to store a pointer value without truncation or loss of information

// serializing
// is used to send memory addresses across networks for example
// because pointers cannot be sent