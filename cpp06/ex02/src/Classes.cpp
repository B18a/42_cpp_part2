/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:41:29 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 09:42:28 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Classes.hpp"
#include<iostream>
#include<cstdlib>
#include<ctime>

/****************************************/
/*			Member Functions			*/
/****************************************/
// Seed only once to avoid getting same sequence of numbers
static int	getRandomNumber(int range)
{
	int 		randomNumber;
	static bool	seeded = false;
	if (!seeded) 
	{
		std::srand(std::time(0));
		seeded = true;
	}
	randomNumber = std::rand() % range;
	return randomNumber;
}

Base*	Base::generate(void)
{
	int random;

	random = getRandomNumber(3);
	if(random == 0)
		return new A;
	else if(random == 1)
		return new B;
	else
		return new C;
}

/****************************************/
/*			Compare Functions			*/
/****************************************/
// Dynamic Cast to get Type object
// Use of Template to avoid redundancy of isClassFunction
template <typename T>
static bool isClass(Base* p)
{
	if(T* t = dynamic_cast<T*>(p))
		return true;
	return false;
}

template <typename T>
static bool isClass(Base& p)
{
	try
	{
		dynamic_cast<T&>(p);
		return true;
	} 
	catch (const std::bad_cast&)
	{
		return false;
	}
}

/****************************************/
/*			Identifier Functions		*/
/****************************************/
/****************************************/
/*				With Pointers			*/
/****************************************/
void	Base::identify(Base* p)
{
	if (!p) 
	{
	std::cout << "Object is null" << std::endl;
	return;
	}
	if(isClass<A>(p))
		std::cout<< "Object is A" << std::endl;
	else if(isClass<B>(p))
		std::cout<< "Object is B" << std::endl;
	else if(isClass<C>(p))
		std::cout<< "Object is C" << std::endl;
	else
		std::cout<< "Object is not A B C" << std::endl;
}

/****************************************/
/*				With References			*/
/****************************************/
void	Base::identify(Base& p)
{
	if(isClass<A>(&p))
		std::cout<< "Object is A" << std::endl;
	else if(isClass<B>(&p))
		std::cout<< "Object is B" << std::endl;
	else if(isClass<C>(&p))
		std::cout<< "Object is C" << std::endl;
	else
		std::cout<< "Object is not A B C" << std::endl;
}
