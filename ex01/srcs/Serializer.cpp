/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:14:22 by dufama            #+#    #+#             */
/*   Updated: 2026/05/15 20:14:22 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Serializer.hpp"
#include <cstdint>

//===== FCO =====

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy) {
	(void)copy;
}

Serializer& Serializer::operator=(const Serializer& assign) {
	(void)assign;
	return *this;
}

Serializer::~Serializer() {}

//===== Methods ======

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

