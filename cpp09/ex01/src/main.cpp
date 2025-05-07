/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:46:55 by ajehle            #+#    #+#             */
/*   Updated: 2025/02/14 10:39:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// container stack

#include"../include/RPN.hpp"


int main(int argc, char** argv)
{

	if(argc != 2)
		return 1;
	if(validate(argv[1]))
	{
		std::cout << "Wrong Input1" << std::endl;
		return 1;
	}
	if(checkSyntaxRPN(argv[1]))
	{
		std::cout << "Wrong Input2" << std::endl;
		return 1;
	}
	calculate(argv[1]);
	return 0;
}




/*

std::stack
push():
Adds an element to the top of the stack.

pop():
Removes the top element.

top():
Accesses the top element.

Unique to Stack:
LIFO (Last In, First Out) structure: Operations follow LIFO order (push at top, pop from top).
Like a queue, empty() and size() are available but it's meant for accessing and manipulating only the top element.

*/

/*

std::stack<int> st;
st.push(1); st.push(2); st.push(3);

while (!st.empty()) {
    std::cout << st.top() << " ";
    st.pop();
}

*/