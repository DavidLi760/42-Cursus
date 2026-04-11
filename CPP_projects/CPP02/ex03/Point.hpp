/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:28 by davli             #+#    #+#             */
/*   Updated: 2024/11/24 16:43:29 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include <cmath>
# include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point(const float x1, const float y1);
		Point(const Point &p);
		Point &operator=(const Point &p);
		~Point();
		Fixed const getX(void) const;
		Fixed const getY(void) const;
	private:
		Fixed const _x;
		Fixed const _y;
};

#endif
