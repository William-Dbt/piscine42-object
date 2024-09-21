#ifndef __COURSEFINISHEDFORM_HPP__
# define __COURSEFINISHEDFORM_HPP__

# include <iostream>
# include "../Form.hpp"

class	CourseFinishedForm: public Form {
	public:
		CourseFinishedForm(FormType p_formType) {
			this->_formType = p_formType;
		}

		virtual void	execute() {
			std::cout << "[CourseFinishedForm] form executed." << std::endl;
		}
};

#endif
