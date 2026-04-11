/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:44:39 by davli             #+#    #+#             */
/*   Updated: 2024/11/24 16:44:40 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value) {}

Fixed& Fixed::operator=(const Fixed &fix)
{
	this->_value = fix._value;
	return (*this);
}

Fixed::~Fixed(void) {}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed::Fixed(const int fix)
{
	int	i = -1;
	int	result = fix;
	while (++i < this->_bits)
		result *= 2;
	this->_value = result;
}

Fixed::Fixed(const float fix)
{
	int	i = -1;
	float	result = fix;
	while (++i < this->_bits)
		result *= 2;
	this->_value = roundf(result);
}

int	Fixed::toInt(void) const
{
	int	i = -1;
	int result = this->_value;
	while (++i < this->_bits)
		result /= 2;
	return (result);
}

float	Fixed::toFloat(void) const
{
	int	i = -1;
	float result = this->_value;
	while (++i < this->_bits)
		result /= 2;
	return (result);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fix)
{
	os << fix.toFloat();
	return (os);
}

int	Fixed::operator>(const Fixed &fix) const
{
	return (this->toFloat() > fix.toFloat());
}

int	Fixed::operator<(const Fixed &fix) const
{
	return (this->toFloat() < fix.toFloat());
}

int	Fixed::operator>=(const Fixed &fix) const
{
	return (this->toFloat() >= fix.toFloat());
}

int	Fixed::operator<=(const Fixed &fix) const
{
	return (this->toFloat() <= fix.toFloat());
}

int	Fixed::operator==(const Fixed &fix) const
{
	return (this->toFloat() == fix.toFloat());
}

int	Fixed::operator!=(const Fixed &fix) const
{
	return (this->toFloat() != fix.toFloat());
}

Fixed	Fixed::operator+(const Fixed &fix) const
{
	return (this->toFloat() + fix.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fix) const
{
	return (this->toFloat() - fix.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fix) const
{
	return (this->toFloat() * fix.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fix) const
{
	return (this->toFloat() / fix.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	now = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (now);
}

Fixed	Fixed::operator--(int)
{
	Fixed	now = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (now);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2)
{
	return ((fix1 < fix2) ? fix1 : fix2);
}

Fixed& Fixed::max(Fixed &fix1, Fixed &fix2)
{
	return ((fix1 > fix2) ? fix1 : fix2);
}

const Fixed& Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	return ((fix1 < fix2) ? fix1 : fix2);
}

const Fixed& Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	return ((fix1 > fix2) ? fix1 : fix2);
}
