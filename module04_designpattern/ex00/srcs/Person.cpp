#include <iostream>
#include "../includes/Person.hpp"

Person::Person(const std::string& p_name) {
	this->_name = p_name;
	this->_currentRoom = NULL;
}

void	Person::setCurrentRoom(Room* room) {
	if (!room) {
		std::cerr << "[Person::setCurrentRoom] ERROR: invalid room." << std::endl;
		return ;
	}
	if (!this->_currentRoom)
		this->_currentRoom->exit(this);

	if (room->canEnter(this)) {
		room->enter(this);
		this->_currentRoom = room;
		std::cout << "[Person::setCurrentRoom] " << this->_name << " is now in room " << room->getId() << '.' << std::endl;
	}
	else
		std::cout << "[Person::setCurrentRoom] Room " << room->getId() << " cannot be accessed." << std::endl;
}

const std::string&	Person::getName() const {
	return this->_name;
}

const Room*	Person::getCurrentRoom() const {
	return this->_currentRoom;
}
