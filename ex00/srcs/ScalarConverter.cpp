/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:23:25 by dufama            #+#    #+#             */
/*   Updated: 2026/05/13 14:50:38 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <climits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& assign) {
	(void)assign;
	return *this;
}

ScalarConverter::~ScalarConverter() {}


//methods

enum InputType {
	CHAR_LITERAL,
	PSEUDO_LITERAL,
	NUMERIC,
	INVALID
};

void printChar(double value, InputType type) {
	std::cout << "char : ";
	if (type == INVALID || type == PSEUDO_LITERAL) {
		std::cout << "impossible" << std::endl;
	}
	else if (value < 0 || value > 127) {
		std::cout << "impossible" << std::endl;
	}
	else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(value)))) {
		std::cout << "Non displayable" << std::endl;
	}
	else {
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}
}

static void printInt(double value, InputType type) {
	std::cout << "int : ";
	if (type == INVALID || type == PSEUDO_LITERAL) {
		std::cout << "impossible" << std::endl;
	}
	else if (value < INT_MIN && value > INT_MAX) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << static_cast<int>(value) << std::endl;
	}
}


static bool isCharLiteral(const std::string& value) {
	return value.length() == 1 
	&& std::isprint(static_cast<unsigned char>(value[0]))
	&& !std::isdigit(static_cast<unsigned char>(value[0]));
}

static bool isPseudoLiteral(std::string value) {
	return value == "nan" || value == "nanf"
	|| value == "+inf" || value == "-inf"
	|| value == "+inff" || value == "-inff";
}

void ScalarConverter::convert(const std::string& value) {
	InputType type = INVALID;
	double conv = 0.0;

	if (isCharLiteral(value)) {
		type = CHAR_LITERAL;
		conv = static_cast<double>(value[0]);
	}
	else if (isPseudoLiteral(value)) {
		type = PSEUDO_LITERAL;
		
	}
	else {
		char* ptr = NULL;
		conv = std::strtod(value.c_str(), &ptr);
		if (ptr != value.c_str() && (*ptr == '\0' || (*ptr == 'f' && *(ptr + 1) == '\0'))) {
			type = NUMERIC;
		}
		else {
			type = INVALID;
		}
	}
	printChar(conv, type);
	printInt(conv, type);
}
