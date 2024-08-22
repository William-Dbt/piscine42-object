#ifndef __SHAPE_HPP__
# define __SHAPE_HPP__

class	Shape {
	public:
		Shape() {}
		virtual ~Shape() {}

		virtual float	calculateArea() = 0;
		virtual float	calculatePerimeter() = 0;
};

#endif
