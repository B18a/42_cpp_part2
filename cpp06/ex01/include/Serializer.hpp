/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:40:48 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 23:57:37 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<cstdint> //for uintptr_t
#include<iostream>
#include"Data.hpp"


#pragma once


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


class Serializer
{
	private:
		Serializer(void);

	public:
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer(void);
		
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif