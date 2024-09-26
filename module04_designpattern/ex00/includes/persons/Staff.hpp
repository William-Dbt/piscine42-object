#ifndef __STAFF_HPP__
# define __STAFF_HPP__

# include "../Person.hpp"

class	Staff: public Person {
	public:
		Staff(const std::string& name): Person(name) {}

		// void	sign(Form*	form);
};

#endif
