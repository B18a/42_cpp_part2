#include<iostream>

template<typename T>
void	printData(T data)
{
	std::cout << data << std::endl;
}


template <typename T, typename Func>

void	iter(T* address, int len, Func func)
{
	int i = 0;
	while(i < len)
	{
		func(address[i]);
		i++;
	}
}