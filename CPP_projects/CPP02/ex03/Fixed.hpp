/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:03 by davli             #+#    #+#             */
/*   Updated: 2024/11/24 16:43:04 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &f);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		int operator>(const Fixed &f) const;
		int operator<(const Fixed &f) const;
		int operator>=(const Fixed &f) const;
		int operator<=(const Fixed &f) const;
		int operator==(const Fixed &f) const;
		int operator!=(const Fixed &f) const;

		Fixed operator+(const Fixed &f) const;
		Fixed operator-(const Fixed &f) const;
		Fixed operator*(const Fixed &f) const;
		Fixed operator/(const Fixed &f) const;

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static			Fixed	&min(Fixed &f1, Fixed &f2);
		static const	Fixed	&min(const Fixed &f1, const Fixed &f2);
		static			Fixed	&max(Fixed &f1, Fixed &f2);
		static const	Fixed	&max(const Fixed &f1, const Fixed &f2);

	private:
		int	_value;
		static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
