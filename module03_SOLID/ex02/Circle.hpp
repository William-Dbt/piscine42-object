#ifndef __CIRCLE_HPP__
# define __CIRCLE_HPP__

# include <cmath>
# include "Shape.hpp"

class	Circle: public Shape {
	public:
		Circle(const int& diameter) {
			this->_diameter = diameter;
		}

		// To calculate the area of a circle, we can use the formula A = (pi / 4) * diameter^2
		virtual float	calculateArea() {
			return ((M_PI / 4) * std::pow(this->_diameter, 2));
		}

		// To know the perimeter of a circle, we can use the formula P = 2 * pi * r where r is diameter / 2
		virtual float	calculatePerimeter() {
			return (2 * M_PI * (this->_diameter / 2));
		}

	private:
		int	_diameter;
};

#endif
