#include <iostream>
#include "Shovel.hpp"

Shovel::Shovel(): _worker(nullptr), _numberOfUses(0) {
	std::cout << "[Shovel] Default constructor called" << std::endl;
}

void	Shovel::use() {
	if (this->_worker == nullptr) {
		std::cout << "Warning: Shovel::use(): no worker have the shovel." << std::endl;
		return ;
	}
	std::cout << "[Shovel] A worker is using me !" << std::endl;
	this->_numberOfUses++;
}

void	Shovel::setWorker(Worker* worker) {
	if (this->_worker != nullptr)
		this->_worker->removeShovel();

	this->_worker = worker;
}

const Worker*	Shovel::getWorker() const {
	return this->_worker;
}
