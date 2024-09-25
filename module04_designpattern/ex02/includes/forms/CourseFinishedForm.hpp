#ifndef __COURSEFINISHEDFORM_HPP__
# define __COURSEFINISHEDFORM_HPP__

# include <iostream>
# include "../Form.hpp"
# include "../Course.hpp"

class	CourseFinishedForm: public Form {
	public:
		CourseFinishedForm(FormType p_formType) {
			this->_formType = p_formType;
			this->_course = NULL;
		}

		void	setCourse(Course* course) {
			if (course)
				this->_course = course;
		}

		const Course*	getCourse() const {
			return this->_course;
		}

		virtual void	execute();

	private:
		Course*	_course;
};

#endif
