/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:00:33 by cgodecke          #+#    #+#             */
/*   Updated: 2023/11/21 16:16:47 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:

	public:
		Serializer(void);
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
		~Serializer(void);
	
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
