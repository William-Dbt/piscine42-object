#ifndef __NEEDCOURSECREATIONFORM_HPP__
# define __NEEDCOURSECREATIONFORM_HPP__

# include <iostream>
# include "../Form.hpp"

class	NeedCourseCreationForm: public Form {
	public:
		virtual void	execute() {
			std::cout << "[NeedCourseCreationForm] form executed." << std::endl;
		}
};

#endif
