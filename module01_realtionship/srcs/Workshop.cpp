#include <iostream>
#include "Workshop.hpp"

Workshop::Workshop() : _name("Unnamed") {
	std::cout << "[Workshop] Default constructor called" << std::endl;
}

Workshop::Workshop(const std::string name) : _name(name) {
	std::cout << "[Workshop] Named constructor called (" << name << ")" << std::endl;
}

Workshop::~Workshop() {
	std::cout << "[Workshop \'" << this->_name << "\'] Destructor called" << std::endl;
}

void	Workshop::registerWorker(Worker* worker) {
	if (worker == nullptr)
		return ;

	if (this->isWorkerRegistred(worker)) {
		std::cerr << "[Workshop \'" << this->_name << "\'] WARNING: worker already registred" << std::endl;
		return ;
	}
	this->_workers.push_back(worker);
	if (!worker->isWorkerInWorkshop(*this))
		worker->registerToWorkshop(*this);

	std::cout << "[Workshop \'" << this->_name << "\'] A new worker is registred." << std::endl;
}

void	Workshop::releaseWorker(Worker* worker) {
	if (worker == nullptr)
		return ;

	if (!this->isWorkerRegistred(worker)) {
		std::cerr << "[Workshop \'" << this->_name << "\'] WARNING: worker isn't registred" << std::endl;
		return ;
	}
	if (worker->isWorkerInWorkshop(*this)) {
		std::cout << "titi" << std::endl;
		worker->releaseWorkshop(*this);
	}

	this->_workers.remove(worker);
	std::cout << "[Workshop \'" << this->_name << "\'] A worker has been released." << std::endl;
}

bool	Workshop::isWorkerRegistred(Worker* worker) {
	if (worker == nullptr)
		return false;

	std::list<Worker*>::iterator	it;

	for (it = this->_workers.begin(); it != this->_workers.end(); it++)
		if ((*it) == worker)
			return true;

	return false;
}

void	Workshop::executeWorkDay() {
	if (this->_workers.size() == 0) {
		std::cerr << "[Workshop \'" << this->_name << "\'] Can't start work day, no workers is registred yet." << std::endl;
		return ;
	}

	std::list<Worker*>::iterator	it;

	for (it = this->_workers.begin(); it != this->_workers.end(); it++)
		(*it)->work(*this);
}

const std::string&	Workshop::getName() const {
	return this->_name;
}
