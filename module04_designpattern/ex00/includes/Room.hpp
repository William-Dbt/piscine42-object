#ifndef __ROOM_HPP__
# define __ROOM_HPP__

# include <vector>
# include "Person.hpp"

class	Room {
	public:
		Room();

		bool	canEnter(Person* person);
		void	enter(Person* person);
		void	exit(Person* person);

		void	printOccupants();

		const long long& getId() const;

	private:
		long long	ID;
		std::vector<Person*>	_occupants;
};

#endif
