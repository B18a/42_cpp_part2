/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:47:17 by ajehle            #+#    #+#             */
/*   Updated: 2025/02/14 12:54:22 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/RPN.hpp"


bool isOperator(char c) 
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

bool isSpace(char c) 
{
	if(c == ' ')
		return true;
	return false;
}

int validate(const std::string& input)
{
	for (char c : input)
	{
		if(!isdigit(c) && !isOperator(c) && c != ' ')
			return true;
	}
	return false;
}


int checkSyntaxRPN(const std::string& input)
{
	size_t i = 0;
	bool NumberFlag = true;
	bool OperatorFlag = false;
	bool SpaceFlag = false;
	while(i < input.size())
	{
		if(NumberFlag)
		{
			if(!isdigit(input[i]))
				return 1;
			NumberFlag = false;
			SpaceFlag = true;
		}
		else if(OperatorFlag)
		{
			if(!isOperator(input[i]))
				return 1;
			OperatorFlag = false;
			SpaceFlag = true;
		}
		else if(SpaceFlag)
		{
			if(!isSpace(input[i]))
				return 1;  // Invalid input, should be a space between tokens
			SpaceFlag = false;  // Space consumed, now check the next token
			if(i + 1 < input.size())  // Check if there's another token
			{
				if(isdigit(input[i + 1]))  // If it's a number
					NumberFlag = true;  // Expecting a number
				else if(isOperator(input[i + 1]))  // If it's an operator
					OperatorFlag = true;  // Expecting an operator
				else
					return 1;  // Invalid input, neither a number nor an operator
			}
		}
		else
			return 1;
		std::cout << input[i] << " index -> " << i << std::endl;
		i++;
	}
	
	return 0;
}


int calculate(const std::string& input)
{
	std::stack<int> st;
	int	i = 0;
	int valueA = 0;
	int valueB = 0;
	for (char c : input)
	{
		if(isdigit(c))
		{
			// std::cout << "next push " << c << std::endl;
			st.push(c - 48);
			i++;
		}
		else if(c == '+' || c == '-' || c == '*' || c == '/')
		{
			// std::cout << "top " << st.top() << std::endl;
			valueA = st.top();
			st.pop();
			// std::cout << "top " << st.top() << std::endl;
			valueB = st.top();
			st.pop();
			// std::cout << valueA << " <-> " << valueB << std::endl;
			switch (c)
			{
				case '+':
					st.push(valueB + valueA);
					break;
				case '-':
					st.push(valueB - valueA);
					break;
				case '*':
					st.push(valueB * valueA);
					break;
				case '/':
					st.push(valueB / valueA);
					break;
			}
		}
	}
	std::cout << st.top() << std::endl;
	return 0;
}
