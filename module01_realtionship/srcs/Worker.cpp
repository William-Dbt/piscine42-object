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

Worker::Worker(int x, int y, int z, int exp) {
	std::cout << "[Worker] Given values constructor" << std::endl;
	this->_position.x = x;
	this->_position.y = y;
	this->_position.z = z;

	this->_statistics.exp = exp;
	this->_statistics.level = (exp > 0 ? (int)(exp / 1000) : 0);
}

void	Worker::setPosition(int x, int y, int z) {
	std::cout << "[Worker] New position ("
			  << x << ", " << y << ", " << z << ')' << std::endl;

	this->_position.x = x;
	this->_position.y = y;
	this->_position.z = z;
}

void	Worker::earnExp(int exp) {
	std::cout << "[Worker] Earned experience (+" << exp << "exp) !" << std::endl;
	this->_statistics.exp += exp;
	if (this->_statistics.exp > 0) { // Worker can reach a new level
		int	newLevel = (int)(this->_statistics.exp / 1000);

		if (newLevel > this->_statistics.level) { // Worker has reached a new level
			std::cout << "[Worker] Reached a new level ! ("
					  << this->_statistics.level << " -> " << newLevel << ") !" << std::endl;

			this->_statistics.level = newLevel;
		}
	}
}

const t_position&	Worker::getPosition() const {
	return this->_position;
}

const t_statistic&	Worker::getStatistics() const {
	return this->_statistics;
}

std::ostream&	operator<<(std::ostream &stream, const Worker &worker) {
	t_position	wPos;
	t_statistic	wStats;

	wPos = worker.getPosition();
	wStats = worker.getStatistics();

	stream << "\n[Worker] Show informations\n";
	stream << "Position: (" << wPos.x << ", " << wPos.y << ", " << wPos.z << ")\n";
	stream << "Statistics:\n";
	stream << "  - Exp: " << wStats.exp << '\n';
	stream << "  - Level: " << wStats.level << std::endl;
	return stream;
}

