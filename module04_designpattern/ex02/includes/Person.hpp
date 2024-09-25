#ifndef __PERSON_HPP__
# define __PERSON_HPP__

# include <string>

class	Room;

class	Person {
	public:
		Person(const std::string& p_name);

		void	setCurrentRoom(Room* room);

		const std::string&	getName() const;

		const Room*	getCurrentRoom() const;

	protected:
		Person() {}

		std::string	_name;
		Room*		_currentRoom;
};

# include "Room.hpp"

#endif
