/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:41:36 by ajehle            #+#    #+#             */
/*   Updated: 2025/01/17 09:41:38 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/Classes.hpp"

int main(void)
{
	Base* a = new A;
	Base* b = new B;
	Base* c = new C;

	c->identify(c);
	b->identify(b);
	a->identify(a);


	Base& refA = *a;

	Base base;
	base.identify(refA);

	return 0;
}

