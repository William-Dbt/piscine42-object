#include <iostream>
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"

int	main() {
	std::cout << "Rectangle(10, 5)" << std::endl;
	Rectangle	rectangle(10, 5);

	std::cout << "Area : " << rectangle.calculateArea() << std::endl;
	std::cout << "Perimeter : " << rectangle.calculatePerimeter() << '\n' << std::endl;

	std::cout << "Triangle(5, 7, 10)" << std::endl;
	Triangle	triangle(5, 7, 10);

	std::cout << "Area : " << triangle.calculateArea() << std::endl;
	std::cout << "Perimeter : " << triangle.calculatePerimeter() << '\n' << std::endl;

	std::cout << "Circle(14)" << std::endl;
	Circle	circle(14);

	std::cout << "Area : " << circle.calculateArea() << std::endl;
	std::cout << "Perimeter : " << circle.calculatePerimeter() << std::endl;
}
