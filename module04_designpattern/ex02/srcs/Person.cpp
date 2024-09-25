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
	this->_currentRoom = room;
}

const std::string&	Person::getName() const {
	return this->_name;
}

const Room*	Person::getCurrentRoom() const {
	return this->_currentRoom;
}
