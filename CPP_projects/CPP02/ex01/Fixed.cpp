/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:03:37 by davli             #+#    #+#             */
/*   Updated: 2024/11/18 15:03:38 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = fix._value;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int fix)
{
	int	i = -1;
	std::cout << "Int constructor called" << std::endl;
	int	result = fix;
	while (++i < this->_bits)
		result *= 2;
	this->_value = result;
}

Fixed::Fixed(const float fix)
{
	int	i = -1;
	std::cout << "Float constructor called" << std::endl;
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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fix)
{
	os << fix.toFloat();
	return (os);
}
