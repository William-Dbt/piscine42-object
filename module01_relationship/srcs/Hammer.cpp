#include <iostream>
#include "Hammer.hpp"

Hammer::Hammer() {
	std::cout << "[Hammer] Constructor called" << std::endl;
}

Hammer::~Hammer() {
	std::cout << "[Hammer] Destructor called" << std::endl;
}

void	Hammer::use() {
	if (this->_worker == NULL) {
		std::cout << "Warning: Hammer::use(): no worker have the hammer." << std::endl;
		return ;
	}
	std::cout << "[Hammer] A worker is using me !" << std::endl;
	this->_numberOfUses++;
	this->_worker->earnExp(10);
}
