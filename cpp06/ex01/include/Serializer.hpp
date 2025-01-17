/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:40:48 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 09:40:50 by ajehle           ###   ########.fr       */
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
		// ~Serializer(void);
		// TO DO



	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif