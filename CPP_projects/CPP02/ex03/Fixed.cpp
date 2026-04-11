/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:42:53 by davli             #+#    #+#             */
/*   Updated: 2024/11/24 16:42:55 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {}


Fixed::Fixed(const Fixed &f) : _value(f._value) {}

Fixed& Fixed::operator=(const Fixed &f)
{
	this->_value = f._value;
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

Fixed::Fixed(const int val)
{
	int i = -1;
	int	result = val;
	while (++i < this->_bits)
		result *= 2;
	this->_value = result;
}

Fixed::Fixed(const float val)
{
	int	i = -1;
	float result = val;
	while (++i < this->_bits)
		result *= 2;
	this->_value = roundf(result);
}

float	Fixed::toFloat(void) const
{
	int i = -1;
	float result = this->_value;
	while (++i < this->_bits)
		result /= 2;
	return (result);
}

int	Fixed::toInt(void) const
{
	int i = -1;
	int result = this->_value;
	while (++i < this->_bits)
		result /= 2;
	return (result);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

int	Fixed::operator>(const Fixed &f) const
{
	return (this->toFloat() > f.toFloat());
}

int	Fixed::operator<(const Fixed &f) const
{
	return (this->toFloat() < f.toFloat());
}

int	Fixed::operator>=(const Fixed &f) const
{
	return (this->toFloat() >= f.toFloat());
}

int	Fixed::operator<=(const Fixed &f) const
{
	return (this->toFloat() <= f.toFloat());
}

int	Fixed::operator==(const Fixed &f) const
{
	return (this->toFloat() == f.toFloat());
}

int	Fixed::operator!=(const Fixed &f) const
{
	return (this->toFloat() != f.toFloat());
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	return (this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	return (this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	return (this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	return (this->toFloat() / f.toFloat());
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
	Fixed	prev = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (prev);
}

Fixed	Fixed::operator--(int)
{
	Fixed	prev = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (prev);
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1 < f2) ? f1 : f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return ((f1 < f2) ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}
