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

void ScalarConverter::printChar(double value) {
	char c = '\0';
	if (value <= 127 && value >= -128) {
		c = static_cast<char>(value);
		if (std::isprint(c)) {
			std::cout << "char : " << c << std::endl;
		}
		else {
			std::cout << "Non displayable" << std::endl;
		}
	}
	else {
		std::cout << "Impossible" << std::endl;
	}
	
}

void ScalarConverter::convert(const std::string& value) {
	char* ptr;
	double conversion = std::strtod(value.c_str(), &ptr);

	if (value.length() == 1 && std::isprint(value[0]) && !std::isdigit(static_cast<char>(value[0]))) {
		conversion = static_cast<char>(value[0]);
	}
	if (ptr == value.c_str()) {
		std::cout << "Pas pu convertir" << std::endl;
	}
	else if (*ptr != '\0') {
		std::cout << "Pas tout converti" << std::endl;
	}
	else {
		std::cout << "Tout converti" << std::endl;
	}
	printChar(conversion);
}
