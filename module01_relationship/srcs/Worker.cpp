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

Worker::~Worker() {
	std::cout << "[Worker] Destructor called" << std::endl;

	while (this->_toolsBag.size() > 0)
		this->_toolsBag.front()->setWorker(nullptr);
}

void	Worker::takeTool(ATool& tool) {
	if (this->isWorkerHaveTool(tool)) {
		std::cout << "[Worker] WARNING: already have tool" << std::endl;
		return ;
	}
	tool.setWorker(this);
	this->_toolsBag.push_front(&tool);
}

void	Worker::removeTool(ATool& tool) {
	if (!this->isWorkerHaveTool(tool)) {
		std::cout << "[Worker] WARNING: doesn't have the tool" << std::endl;
		return ;
	}
	this->_toolsBag.remove(&tool);
}

bool	Worker::isWorkerHaveTool(ATool& tool) {
	if (this->_toolsBag.size() == 0)
		return false;

	std::list<ATool*>::iterator	it;

	for (it = this->_toolsBag.begin(); it != this->_toolsBag.end(); it++)
		if ((*it) == &tool)
			return true;

	return false;
}

void	Worker::registerToWorkshop(Workshop& workshop) {
	if (this->isWorkerInWorkshop(workshop)) {
		std::cerr << "[Worker] WARNING: already in workshop" << std::endl;
		return ;
	}
	this->_workshops.push_back(&workshop);
	if (!workshop.isWorkerRegistred(this))
		workshop.registerWorker(this);
}

void	Worker::releaseWorkshop(Workshop& workshop) {
	if (!this->isWorkerInWorkshop(workshop)) {
		std::cerr << "[Worker] WARNING: isn't in workshop" << std::endl;
		return ;
	}
	this->_workshops.remove(&workshop);
	if (workshop.isWorkerRegistred(this))
		workshop.releaseWorker(this);
}

bool	Worker::isWorkerInWorkshop(Workshop& workshop) {
	if (this->_workshops.size() == 0)
		return false;

	std::list<Workshop*>::iterator	it;

	for (it = this->_workshops.begin(); it != this->_workshops.end(); it++)
		if ((*it) == &workshop)
			return true;

	return false;
}

void	Worker::work(Workshop& workshop) {
	if (this->_workshops.size() == 0) {
		std::cerr << "[Worker] WARNING: hasn't registred to a workshop yet, worker can't work" << std::endl;
		return ;
	}
	if (!this->isWorkerInWorkshop(workshop)) {
		std::cerr << "[Worker] WARNING: isn't registred to workshop \'" << workshop.getName() <<  "\', can't start working" << std::endl;
		return ;
	}
	std::cout << "[Worker] Initiate work at workshop " << workshop.getName() << std::endl;
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
	stream << "  - Level: " << wStats.level << "\n";
	return stream;
}
