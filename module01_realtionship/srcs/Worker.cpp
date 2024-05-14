#include <iostream>
#include "Worker.hpp"

Worker::Worker() {
	std::cout << "[Worker] Default constructor" << std::endl;
	this->_position.x = 0;
	this->_position.y = 0;
	this->_position.z = 0;

	this->_statistics.exp = 0;
	this->_statistics.level = 0;
}

Worker::Worker(int x, int y, int z, int level, int exp) {
	std::cout << "[Worker] Given values constructor" << std::endl;
	this->_position.x = x;
	this->_position.y = y;
	this->_position.z = z;

	this->_statistics.exp = exp;
	this->_statistics.level = level;
}

const t_position&	Worker::getPosition() const {
	return this->_position;
}

const t_statistic&	Worker::getStatistics() const {
	return this->_statistics;
}
