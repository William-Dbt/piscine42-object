#ifndef __ROOM_HPP__
# define __ROOM_HPP__

# include <vector>
# include "Person.hpp"

typedef std::vector<Person*>::iterator	ite_occupants;

class	Room {
	public:
		Room();

		virtual bool	canEnter(Person* person);

		void	enter(Person* person);
		void	exit(Person* person);

		void	printOccupants();
		bool	isPersonInRoom(Person* person);

		const long long& getId() const;

	protected:
		static long long		ID;
		std::vector<Person*>	_occupants;
};

#endif
