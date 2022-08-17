/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:54:34 by gclausse          #+#    #+#             */
/*   Updated: 2022/08/11 13:54:34 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed(): _value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int Constructor called" << std::endl;
	this->_value = num << this->_fract_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float Constructor called" << std::endl;
	this->_value = (int)roundf(num * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &b)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &b)
		this->_value = b.getRawBits();
	return *this;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void) const
{
	return (int)(this->_value >> this->_fract_bits);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return (output);
}