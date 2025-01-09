
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