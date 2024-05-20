#include <iostream>
#include "Hammer.hpp"

Hammer::Hammer(): _worker(nullptr), _numberOfUses(0) {
	std::cout << "[Hammer] Default constructor called" << std::endl;
}

Hammer::~Hammer() {
	std::cout << "[Hammer] Destructor called" << std::endl;
}

void	Hammer::use() {
	if (this->_worker == nullptr) {
		std::cout << "Warning: Hammer::use(): no worker have the hammer." << std::endl;
		return ;
	}
	std::cout << "[Hammer] A worker is using me !" << std::endl;
	this->_numberOfUses++;
}

void	Hammer::setWorker(Worker* worker) {
	if (this->_worker != nullptr)
		this->_worker->removeTool(*this);

	this->_worker = worker;
}

const Worker*	Hammer::getWorker() const {
	return this->_worker;
}
