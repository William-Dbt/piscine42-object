#ifndef __ROOM_HPP__
# define __ROOM_HPP__

# include <vector>

class	Person;

class	Room {
	public:
		Room();

		bool	canEnter(Person* person);
		void	enter(Person* person);
		void	exit(Person* person);

		void	printOccupants();

		bool	isSecretarialOffice();

		std::vector<Person*>::iterator	getItOfPerson(Person* person);

		const long long&	getId() const;

	private:
		long long	_id;

		std::vector<Person*>	_occupants;
};

# include "Person.hpp"

#endif
