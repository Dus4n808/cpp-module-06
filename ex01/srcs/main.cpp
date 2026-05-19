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
#include <iostream>
#include <ostream>
#include <stdint.h>

static void printData(Data *ptr) {
	std::cout << "First name : " << ptr->firstName << std::endl;
  	std::cout << "Last name : " << ptr->lastName << std::endl;
   	std::cout << "Age : " << ptr->age << std::endl;
}

int main() {
	Data toTest;
	toTest.firstName = "John";
	toTest.lastName = "Doe";
	toTest.age = 100;

	printData(&toTest);
	uintptr_t rawValue = Serializer::serialize(&toTest);
	std::cout << rawValue << std::endl;
	Data *newValue = Serializer::deserialize(rawValue);
	uintptr_t newRawValue = Serializer::serialize(newValue);
	std::cout << newRawValue << std::endl;
	printData(newValue);
	std::cout << (newRawValue == rawValue) << std::endl;
}
