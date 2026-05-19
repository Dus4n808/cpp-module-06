/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:24:14 by dufama            #+#    #+#             */
/*   Updated: 2026/05/12 17:24:14 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>


int main(int argc, char *argv[]) {
	if (argc > 3) {
		std::cerr << "Usage: ./exec [number]" << std::endl;
		return EXIT_FAILURE;
	}
	std::string arg = "";
	if (argv[1]) {
		arg = argv[1];
		ScalarConverter::convert(arg);
	}
}