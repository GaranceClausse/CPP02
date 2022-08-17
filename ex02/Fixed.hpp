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
#include <cmath>


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

	bool operator>(Fixed fixed)const;
	bool operator<(Fixed fixed)const;
	bool operator>=(Fixed fixed)const;
	bool operator<=(Fixed fixed)const;
	bool operator==(Fixed fixed)const;
	bool operator!=(Fixed fixed)const;

	float operator+(Fixed fixed)const;
	float operator-(Fixed fixed)const;
	float operator*(Fixed fixed)const;
	float operator/(Fixed fixed)const;
	
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed &min(Fixed &num1, Fixed &num2);
	static const Fixed &min(Fixed const &num1, Fixed const &num2);
	static Fixed &max(Fixed &num1, Fixed &num2);
	static const Fixed &max(Fixed const &num1, const Fixed &num2);
};

std::ostream    &operator<<(std::ostream &output, Fixed const &fixed);