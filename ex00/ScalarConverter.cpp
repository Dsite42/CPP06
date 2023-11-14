/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:09:00 by cgodecke          #+#    #+#             */
/*   Updated: 2023/11/14 17:36:37 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int checkType(std::string literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
	{
		if (isprint(literal[0]))
			return (0);
		else
			std::cout << "Non displayable";
	}
	else if (literal[literal.length() - 1] == 'f')
	{
		return (2);
	}

	return (10);
}

void ScalarConverter::convert(std::string literal)
{
	double literal_to_cast;
	(void) literal;
	float test = 3.5f;
	std::cout << test << std::endl;

	switch (checkType(literal))
	{
	case 0:
		literal_to_cast = literal[0];
		std::cout << "char: '" << (char)literal_to_cast << "'" << std::endl;
		break;
	case 2:
		literal_to_cast = (double)std::stof(literal);
		std::cout << "float: '" << (float)literal_to_cast << "'" << std::endl;
		break;
	
	default:
		break;
	}
}
