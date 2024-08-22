#ifndef __TRIANGLE_HPP__
# define __TRIANGLE_HPP__

# include <cmath>
# include "Shape.hpp"

class	Triangle: public Shape {
	public:
		Triangle(const int& lengthFirstSide,
				const int& lengthSecondSide,
				const int& lengthThirdSide)
		{
			this->_sidesLength[0] = lengthFirstSide;
			this->_sidesLength[1] = lengthSecondSide;
			this->_sidesLength[2] = lengthThirdSide;
		}

		// To know the area of a triangle, the formula is A = Base * Heigth / 2 but, we don't know the Heigth of the triangle
		// In that case, we can use the Héron formula which said that A = SquareRoot(p(p - a)(p-b)(p-c)) where p is the half of the perimeter and a, b and c the length of the sides of the triangle
		// To know p we'll use the calculatePerimeter() function
		virtual float	calculateArea() {
			int	a = this->_sidesLength[0];
			int	b = this->_sidesLength[1];
			int	c = this->_sidesLength[2];
			int	p = this->calculatePerimeter() / 2;

			return (std::sqrt(p * (p - a) * (p - b) * (p - c)));
		}

		// The perimeter of the triangle is P = a + b + c where a, b and c are the length of the sides of the triangle
		virtual float	calculatePerimeter() {
			return (this->_sidesLength[0] + this->_sidesLength[1] + this->_sidesLength[2]);
		}

	private:
		int	_sidesLength[3];
};

#endif
