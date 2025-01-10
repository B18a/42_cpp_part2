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

