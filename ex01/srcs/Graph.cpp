#include "Graph.hpp"
#include <iostream>
#include <string>

Graph::Graph() {
	this->_size.x = 0;
	this->_size.y = 0;
}

void	Graph::addVector(float x, float y) {
	t_vector2	buffer;

	if (x < 0 || y < 0) {
		std::cout << "ERROR: Points must be greater than 0.\n";
		std::cout << "Vector2(" << x << ',' << y << ") cannot be added." << std::endl;
		return ;
	}
	if (x > this->_size.x)
		this->_size.x = x;

	if (y > this->_size.y)
		this->_size.y = y;

	buffer.x = x;
	buffer.y = y;
	this->_points.push_back(buffer);
}

void	Graph::addVector(t_vector2 points) {
	if (points.x < 0 || points.y < 0) {
		std::cout << "ERROR: Points must be greater than 0.\n";
		std::cout << "Vector2(" << points.x << ',' << points.y << ") cannot be added." << std::endl;
		return ;
	}
	if (points.x > this->_size.x)
		this->_size.x = points.x;

	if (points.y > this->_size.y)
		this->_size.y = points.y;

	this->_points.push_back(points);
}

void	Graph::show() {
	std::string	graph;

	for (int maxX = this->_size.x + 1; maxX >= 0; maxX--) {
		std::cout << PROMPT << maxX;
		for (int i = 0; i <= this->_size.y + 1; i++) {
			if (this->isPointsInList(maxX, i))
				std::cout << " X";
			else
				std::cout << " .";
		}
		std::cout << '\n';
	}
	std::cout << PROMPT << ' ';
	for (int i = 0; i <= this->_size.y + 1; i++)
		std::cout << ' ' << i;

	std::cout << std::endl;
}

bool	Graph::isPointsInList(float x, float y) {
	std::list<t_vector2>::iterator	it;

	for (it = this->_points.begin(); it != this->_points.end(); it++)
		if ((int)(*it).x == (int)x && (int)(*it).y == (int)y)
			return true;

	return false;
}
