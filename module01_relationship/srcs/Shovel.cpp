#include <iostream>
#include "Shovel.hpp"

Shovel::Shovel() {
	std::cout << "[Shovel] Constructor called" << std::endl;
}

Shovel::~Shovel() {
	std::cout << "[Shovel] Destructor called" << std::endl;
}

void	Shovel::use() {
	if (this->_worker == nullptr) {
		std::cout << "Warning: Shovel::use(): no worker have the shovel." << std::endl;
		return ;
	}
	std::cout << "[Shovel] A worker is using me !" << std::endl;
	this->_numberOfUses++;
	this->_worker->earnExp(20);
}
