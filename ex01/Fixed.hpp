/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:54:27 by gclausse          #+#    #+#             */
/*   Updated: 2022/08/11 13:54:27 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <math.h>

class Fixed
{
private:
	int _value;
	static const int _fract_bits;

public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int num);
	Fixed(const float num);

	Fixed &operator=(const Fixed &b);

	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream    &operator<<(std::ostream &output, Fixed const &fixed);