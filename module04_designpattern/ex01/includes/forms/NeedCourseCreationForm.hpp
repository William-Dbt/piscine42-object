#ifndef __NEEDCOURSECREATIONFORM_HPP__
# define __NEEDCOURSECREATIONFORM_HPP__

# include <iostream>
# include "../Form.hpp"

class	NeedCourseCreationForm: public Form {
	public:
		NeedCourseCreationForm(FormType p_formType) {
			this->_formType = p_formType;
		}

		virtual void	execute() {
			std::cout << "[NeedCourseCreationForm] form executed." << std::endl;
		}
};

#endif
