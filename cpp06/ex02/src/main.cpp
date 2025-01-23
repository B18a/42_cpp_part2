/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:41:36 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/23 12:58:37 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Classes.hpp"
#include<iostream>
#include<cstdlib>
#include<ctime>

/****************************************/
/*			Compare Functions			*/
/****************************************/
// Dynamic Cast to get Type object
// Use of Template to avoid redundancy of isClassFunction
template <typename T>
static bool isClass(Base* p)
{
	if(dynamic_cast<T*>(p))
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
void	identify(Base* p)
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
void	identify(Base& p)
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

/****************************************/
/*			generate Random				*/
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

Base*	generate(void)
{
	int random;

	random = getRandomNumber(3);
	if(random == 0)
	{
		std::cout << "generated Object as A" << std::endl;
		return new A;
	}
	else if(random == 1)
	{
		std::cout << "generated Object as B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "generated Object as C" << std::endl;
		return new C;
	}
}

/****************************************/
/*				Main					*/
/****************************************/
int main(void)
{
	Base* a;
	Base* b;
	Base* c;

	a = generate();
	b = generate();
	c = generate();

	Base& refA = *a;
	Base& refB = *b;
	Base& refC = *c;
	
	std::cout << "\nidentify as pointer" << std::endl;
	identify(a);
	identify(b);
	identify(c);

	std::cout << "\nidentify as reference" << std::endl;
	identify(refA);
	identify(refB);
	identify(refC);

	delete a;
	delete b;
	delete c;

	return 0;
}

