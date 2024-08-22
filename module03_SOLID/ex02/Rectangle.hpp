#ifndef __RECTANGLE_HPP__
# define __RECTANGLE_HPP__

# include "Shape.hpp"

class	Rectangle: public Shape {
	public:
		Rectangle(const int& length, const int& width) {
			this->_length = length;
			this->_width = width;
		}

		// Formula for area of a rectangle is A = L * l
		virtual float	calculateArea() {
			return (this->_length * this->_width);
		}

		// Formula for perimeter of a rectangle is P = (L + W) * 2
		virtual float	calculatePerimeter() {
			return ((this->_length + this->_width) * 2);
		}

	private:
		int	_length;
		int	_width;
};

#endif
