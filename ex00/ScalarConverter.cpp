/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:09:00 by cgodecke          #+#    #+#             */
/*   Updated: 2023/11/17 14:55:15 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
bool isAllDigit(std::string literal)
{
	bool is_point = false;

	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (!isdigit(static_cast<unsigned char>(literal[i])))
		{
			if (i == 0 && (static_cast<unsigned char>(literal[i]) == '-' || static_cast<unsigned char>(literal[i]) == '+'))
				continue;
			else if (literal[i] == '.' && is_point == false)
			{
				is_point = true;
				continue;
			}
			else
				return (false);
		}
	}

	return (true);
}

bool isFloat(std::string literal)
{
	bool is_point = false;

	if (literal[literal.length() - 1] != 'f')
		return (false);

	for (size_t i = 0; i < literal.length() - 1; ++i)
	{
		if (!isdigit(static_cast<unsigned char>(literal[i])))
		{
			if (i == 0 && (static_cast<unsigned char>(literal[i]) == '-' || static_cast<unsigned char>(literal[i]) == '+'))
				continue;
			else if (i != 0 && literal[i] == '.' && is_point == false && literal[i + 1] != 'f')
			{
				is_point = true;
				continue;
			}
			else
				return (false);
		}
	}

	return (true);
}

int checkType(std::string literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
	{
		if (isprint(literal[0]))
			return (0);
		else
			std::cout << "Non displayable";
	}
	else if (literal.length() == 1 && isdigit(literal[0]))
	{
		return (1);
	}

	else if (isFloat(literal))
	{
		return (2);
	}
	else if (isAllDigit(literal))
		return (3);

	return (10);
}

void printAll(double &literal_to_cast)
{
	std::cout << "char: '" << static_cast<char>(literal_to_cast) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(literal_to_cast) << std::endl;
	std::cout << "float: " << static_cast<float>(literal_to_cast) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(literal_to_cast) << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	double literal_to_cast;
	(void) literal;

	switch (checkType(literal))
	{
	case 0:
		literal_to_cast = static_cast<double>(literal[0]);
		//std::cout << "char: '" << static_cast<char>(literal_to_cast) << "'" << std::endl;
		break;
	case 1:
		literal_to_cast = static_cast<double>(std::stoi(literal));
		//std::cout << "int: " << static_cast<int>(literal_to_cast) << std::endl;
		break;
	case 2:
		literal_to_cast = static_cast<double>(std::stof(literal));
		//std::cout << "float: " << static_cast<float>(literal_to_cast) << "f" << std::endl;
		break;
	case 3:
		literal_to_cast = static_cast<double>(std::stod(literal));
		//std::cout << "double: " << static_cast<double>(literal_to_cast) << std::endl;

	default:
		std::cout << "nix dabei\n"; 
		return;
	}

	printAll(literal_to_cast);

}
