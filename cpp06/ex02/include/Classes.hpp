
// #include<iostream>

#pragma once

/****************************************/
/*				Class Base				*/
/****************************************/
#ifndef BASE_HPP
#define BASE_HPP


class Base
{
	private:

	public:
		virtual ~Base(){};

		Base*	generate(void); // It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free to use anything you like for the random choice implementation.
		void	identify(Base* p); //It prints the actual type of the object pointed to by p: "A", "B" or "C".
		void	identify(Base& p); //It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer inside this function is forbidden
};

#endif


/****************************************/
/*				Class A					*/
/****************************************/
#ifndef A_HPP
#define A_HPP

class A : public Base {};

#endif

/****************************************/
/*				Class B					*/
/****************************************/
#ifndef B_HPP
#define B_HPP

class B : public Base {};

#endif

/****************************************/
/*				Class C					*/
/****************************************/
#ifndef C_HPP
#define C_HPP

class C : public Base {};

#endif

