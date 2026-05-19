/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:13:29 by dufama            #+#    #+#             */
/*   Updated: 2026/05/15 20:13:29 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data {
	std::string firstName;
	std::string lastName;
	int age;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& assign);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif