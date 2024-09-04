#ifndef __STAFF_HPP__
# define __STAFF_HPP__

# include "../Person.hpp"
# include "../Form.hpp"

class	Staff: public Person {
	public:
		void	sign(Form* p_form);
};

#endif
