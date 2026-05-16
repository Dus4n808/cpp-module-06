/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:14:40 by dufama            #+#    #+#             */
/*   Updated: 2026/05/15 20:14:40 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Serializer.hpp"
#include <cstdint>
#include <iostream>
#include <ostream>

void printData(Data *ptr) {
	std::cout << "First name : " << ptr->firstName << std::endl;
	std::cout << "Last name : " << ptr->lastName << std::endl;
	std::cout << "Age : " << ptr->age << std::endl;
}

int main() {

	Data test;
	test.firstName = "Dusan";
	test.lastName = "Fama";
	test.age = 29;
	printData(&test);

	uintptr_t raw = Serializer::serialize(&test);
	std::cout << "Raw value of adress test : " << raw << std::endl;

	Data *newPtr = Serializer::deserialize(raw);
	printData(newPtr);
	uintptr_t newRaw = Serializer::serialize(newPtr);
	std::cout << "Raw value of adress newPtr " << newRaw << std::endl;
	std::cout << (&test == newPtr) << std::endl;
}