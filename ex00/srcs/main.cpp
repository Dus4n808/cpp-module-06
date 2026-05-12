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

#include "../headers/ScalarConvert.hpp"
#include <iostream>
#include <ostream>
#include <string>


int main(int argc, char *argv[]) {
	if (argc > 3)
		std::cerr << "Error" << std::endl;
	std::string arg = "";
	if (argv[1]) {
		arg = argv[1];
		std::cout << arg << std::endl;
	}
}