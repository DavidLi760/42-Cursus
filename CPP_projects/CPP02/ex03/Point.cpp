/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:20 by davli             #+#    #+#             */
/*   Updated: 2024/11/24 16:43:21 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
: _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x1, const float y1) : _x(Fixed(x1)), _y(Fixed(y1)) {}

Point::Point(const Point &p)
: _x(p._x), _y(p._y) {}

Point::~Point(void) {}

Point&	Point::operator=(const Point &p)
{
	std::cout << "Error : Use of constructor needed, constant value." << std::endl;
	return (*this);
}

Fixed const	Point::getX(void) const
{
	return (this->_x);
}

Fixed const	Point::getY(void) const
{
	return (this->_y);
}
