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
	//std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int Constructor called" << std::endl;
	this->_value = num << this->_fract_bits;
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float Constructor called" << std::endl;
	this->_value = roundf(num * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed& copy)
{
	//std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &b)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &b)
		this->_value = b.getRawBits();
	return *this;
}

/************************************************************************/
//Opérateurs de comparaison

bool	Fixed::operator>(Fixed const &fixed) const {
	return getRawBits() > fixed.getRawBits();
}

bool	Fixed::operator<(Fixed const &fixed) const {
	return getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=(Fixed const &fixed) const {
	return getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=(Fixed const &fixed) const {
	return getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==(Fixed const &fixed) const {
	return getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=(Fixed const &fixed) const {
	return getRawBits() != fixed.getRawBits();
}

/************************************************************************/
//Opérateurs arithmétiques

float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

/*************************************************************************/

Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

/*************************************************************************/

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_value;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_value;
	return (tmp);
}

/*************************************************************************/

float	Fixed::toFloat(void)const
{
	return ((float)this->_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_value >> this->_fract_bits);
}

/************************************************************************/
// Fonctions membres publiques surchargées pour retourner + petit/grand nombre

Fixed	&Fixed::min(Fixed &num1, Fixed &num2)
{
	return (num1 < num2 ? num1 : num2);
}

const Fixed	&Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1.toFloat() <= num2.toFloat())
		return (num1);
	else
		return (num2);
}

Fixed	&Fixed::max(Fixed &num1, Fixed &num2)
{
	return (num1 > num2 ? num1 : num2);
}

const Fixed	&Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1.toFloat() >= num2.toFloat())
		return (num1);
	else
		return (num2);
}


/*************************************************************************/

int	Fixed::getRawBits(void)const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return (output);
}