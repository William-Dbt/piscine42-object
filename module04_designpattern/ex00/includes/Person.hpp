#ifndef __PERSON_HPP__
# define __PERSON_HPP__

# include <string>
# include "Room.hpp"

class	Person {
	public:
		Person(const std::string& name) {
			this->_name = name;
		}

		void	setCurrentRoom(Room* room) {
			this->_currentRoom = room;
		}

		Room*	getCurrentRoom() const {
			return this->_currentRoom;
		}

		const std::string&	getName() const {
			return this->_name;
		}

	protected:
		std::string	_name;
		Room*		_currentRoom;
};

#endif
