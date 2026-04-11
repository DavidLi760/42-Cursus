/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:02:58 by davli             #+#    #+#             */
/*   Updated: 2024/11/18 15:03:24 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>

class Fixed
{
	private:
		int	_value;
		static const int _bits = 8;
	public:
		Fixed();
		Fixed(const int fix);
		Fixed(const float fix);
		Fixed(const Fixed &fix);
		Fixed &operator=(const Fixed &fix);
		~Fixed();
		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
