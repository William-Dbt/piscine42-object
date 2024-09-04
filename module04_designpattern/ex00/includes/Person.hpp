#ifndef __PERSON_HPP__
# define __PERSON_HPP__

# include <string>

class	Room;

class	Person {
	public:
		Person(const std::string& p_name);

		Room*	getCurrentRoom() {
			return this->_currentRoom;
		}

	private:
		std::string	_name;
		Room*		_currentRoom;
};

# include "Room.hpp"

#endif
