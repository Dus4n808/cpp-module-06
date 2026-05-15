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

#include "../headers/Data.hpp"
#include <cstdint>
#include <iostream>

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