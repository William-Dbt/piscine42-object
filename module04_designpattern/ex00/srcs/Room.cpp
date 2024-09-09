#include <iostream>
#include "../includes/Room.hpp"

long long	Room::ID = 0;

Room::Room() {
	this->ID = this->ID++;
}

bool	Room::canEnter(Person* person) {
	if (!person) {
		std::cerr << "[Room::canEnter] ERROR: person invalid." << std::endl;
		return false;
	}
	if (this->isPersonInRoom(person)) {
		std::cout << "[Room::canEnter] WARN: person is already in the room." << std::endl;
		return false;
	}
	return true;
}

void	Room::enter(Person* person) {
	this->_occupants.push_back(person);
}

void	Room::exit(Person* person) {
	ite_occupants	it;

	for (it = this->_occupants.begin(); it != this->_occupants.end(); it++) {
		if ((*it) == person)
			it = this->_occupants.erase(it);

		if (it == this->_occupants.end())
			return ;
	}
}

void	Room::printOccupants() {
	ite_occupants	it;

	std::cout << "----- OCCUPANTS OF ROOM " << this->ID << " -----\n";
	for (it = this->_occupants.begin(); it != this->_occupants.end(); it++)
		std::cout << '-' << (*it)->getName() << '\n';

	std::cout << "-------------------------" << std::endl;
}

bool	Room::isPersonInRoom(Person* person) {
	if (!person)
		return false;

	ite_occupants	it;

	for (it = this->_occupants.begin(); it != this->_occupants.end(); it++)
		if ((*it) == person)
			return true;

	return false;
}

const long long& Room::getId() const {
	return this->ID;
}
