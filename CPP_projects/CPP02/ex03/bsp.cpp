/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:42:43 by davli             #+#    #+#             */
/*   Updated: 2024/11/24 16:42:45 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool	sign(const Point &a, const Point &b, const Point &c, const Point &d)
{
	Fixed	result;

	result = (b.getX() - a.getX()) * (d.getY() - c.getY()) - (d.getX() - c.getX()) * (b.getY() - a.getY());
	return (result > 0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	d1, d2, d3;
	
	d1 = sign(a, point, a, b);
	d2 = sign(b, point, b, c);
	d3 = sign(c, point, c, a);

	return (d1 == d2 && d2 == d3);
}
