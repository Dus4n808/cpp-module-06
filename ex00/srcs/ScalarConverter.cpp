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
#include <iostream>
#include <iomanip>
#include <limits>


// ===== FCO =====
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& assign) {
	(void)assign;
	return *this;
}

ScalarConverter::~ScalarConverter() {}



//Enum of differents type of literals
enum InputType {
	CHAR_LITERAL,
	PSEUDO_LITERAL,
	NUMERIC,
	INVALID
};

// ===== Utils Func ======


static void printChar(double value, InputType type) {
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
	else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << static_cast<int>(value) << std::endl;
	}
}

static void printFloat(double value, InputType type) {
	std::cout << "float : ";

	if (type == INVALID) {
		std::cout << "impossible" << std::endl;
		return;
	}
	if (value != value) {
		std::cout << "nanf" << std::endl;
		return;
	}
	if (value == std::numeric_limits<double>::infinity()) {
		std::cout << "+inff" << std::endl;
		return;
	}
	if (value == -std::numeric_limits<double>::infinity()) {
		std::cout << "-inff" << std::endl;
		return;
	}
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
		std::cout << "impossible" << std::endl;
	}

	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	
}

static void printDouble(double value, InputType type) {
	std::cout << "double : ";

	if (type == INVALID) {
		std::cout << "impossible" << std::endl;
		return;
	}
	if (value != value) {
		std::cout << "nan" << std::endl;
		return; 
	}
	if (value == std::numeric_limits<double>::infinity()) {
		std::cout << "+inf" << std::endl;
		return;

	}
	if (value == -std::numeric_limits<double>::infinity()) {
		std::cout << "-inf" << std::endl;
		return;
	}
	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

//Check if is a unique literal char = 'A'
static bool isCharLiteral(const std::string& value) {
	return value.length() == 1 
	&& std::isprint(static_cast<unsigned char>(value[0]))
	&& !std::isdigit(static_cast<unsigned char>(value[0]));
}

static bool isPseudoLiteral(std::string value) {
	return value == "nan" || value == "nanf"
	|| value == "+inf" || value == "-inf"
	|| value == "+inff" || value == "-inff"
	|| value == "inf" || value == "inff";
}


// ===== Methods =====
void ScalarConverter::convert(const std::string& value) {
	InputType type = INVALID;
	double conv = 0.0;

	if (isCharLiteral(value)) {
		type = CHAR_LITERAL;
		conv = static_cast<double>(value[0]);
	}
	else if (isPseudoLiteral(value)) {
		type = PSEUDO_LITERAL;
		if (value == "nan" || value == "nanf")
			conv = std::numeric_limits<double>::quiet_NaN();
		else if (value == "+inf" || value == "inf" || value == "+inff" || value == "inff")
			conv = std::numeric_limits<double>::infinity();
		else
			conv = -std::numeric_limits<double>::infinity();
 ;
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
	printFloat(conv, type);
	printDouble(conv, type);
}
