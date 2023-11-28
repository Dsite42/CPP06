/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:08:54 by cgodecke          #+#    #+#             */
/*   Updated: 2023/11/28 11:09:30 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>


class ScalarConverter
{
	private:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
		static void outputAsAll(double value, bool isFloatingPoint, int precision);

	public:
		// Member function
		static void convert(const std::string& literal);
};

#endif
