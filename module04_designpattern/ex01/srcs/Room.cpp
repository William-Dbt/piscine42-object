#include <iostream>
#include "../includes/Room.hpp"

Room::Room() {
	static int	lastIdUsed = 0;

	this->_id = lastIdUsed++;
}

bool	Room::canEnter(Person* person) {
	if (!person)
		return false;

	if (person->getCurrentRoom() == this)
		return false;

	return true;
}

void	Room::enter(Person* person) {
	if (!person)
		return ;

	if (this->getItOfPerson(person) != this->_occupants.end())
		this->_occupants.push_back(person);
}

void	Room::exit(Person* person) {
	if (!person)
		return ;

	std::vector<Person*>::iterator	it = this->getItOfPerson(person);

	if (it != this->_occupants.end())
		this->_occupants.erase(it);
}

void	Room::printOccupants() {
	std::cout << "----- Occupants of room " << this->_id << "-----\n";

	std::vector<Person*>::iterator	it;

	for (it = this->_occupants.begin(); it != this->_occupants.end(); it++)
		std::cout << "- " << (*it)->getName() << '\n';

	std::cout << "------------------------" << std::endl;
}

bool	Room::isSecretarialOffice() {
	return false;
}

std::vector<Person*>::iterator	Room::getItOfPerson(Person* person) {
	if (this->_occupants.size() == 0)
		return this->_occupants.end();

	std::vector<Person*>::iterator	it;

	for (it = this->_occupants.begin(); it != this->_occupants.end(); it++)
		if ((*it) == person)
			return it;

	return this->_occupants.end();
}

const long long&	Room::getId() const {
	return this->_id;
}
