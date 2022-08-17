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

class Fixed
{
private:
	int _value;
	static const int _fract_bits;

public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed &operator=(const Fixed &b);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
