/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:11 by davli             #+#    #+#             */
/*   Updated: 2024/11/24 16:43:12 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iomanip>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	angleA(1.0, 1.0);
	Point	angleB(3.0, 9.0);
	Point	angleC(5.0, 2.0);
	Point	point(2.0, 2.0);

	bool result;

	std::cout << "A: x=" << angleA.getX() << ", y=" << angleA.getY() <<std::endl; 
	std::cout << "B: x=" << angleB.getX() << ", y=" << angleB.getY() <<std::endl; 
	std::cout << "C: x=" << angleC.getX() << ", y=" << angleC.getY() <<std::endl; 
	std::cout << "Point : x=" << point.getX() << ", y=" << point.getY() <<std::endl; 
	result = bsp(angleA, angleB, angleC, point);
	std::cout << std::endl;
	if (result == true)
		std::cout << "The point is inside of the triangle" << std::endl;
	else
		std::cout << "The point is outside of the triangle" << std::endl;
	return (0);
}
