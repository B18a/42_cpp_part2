#include"../include/Template.hpp"
#include<iostream>

int main(void)
{
	int arr[5] = {5,4,3,1,8};

	::iter(arr, 5, printData<int>);

}