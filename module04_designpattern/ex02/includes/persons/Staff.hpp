#ifndef __STAFF_HPP__
# define __STAFF_HPP__

# include <iostream>
# include "../Person.hpp"
# include "../Form.hpp"

class	Staff: public Person {
	public:
		Staff(const std::string& name): Person(name) {}

		void	sign(Form* p_form) {
			std::cout << this->_name << " has sign form " << p_form->getFormType() << "." << std::endl;
		}
};

#endif
