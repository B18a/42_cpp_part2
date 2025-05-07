/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:47:21 by ajehle            #+#    #+#             */
/*   Updated: 2025/02/07 16:32:34 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stack>
#include<iostream>

#ifndef RPN_HPP
#define RPN_HPP

int validate(const std::string& input);
int checkSyntaxRPN(const std::string& input);
int calculate(const std::string& input);


#endif