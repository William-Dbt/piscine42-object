#ifndef __COURSEFINISHEDFORM_HPP__
# define __COURSEFINISHEDFORM_HPP__

# include "../Form.hpp"
# include "../Course.hpp"

class	CourseFinishedForm: public Form {
	public:
		CourseFinishedForm(FormType type);

		void	assignCourse(Course* course);

		void	execute();

	private:
		Course*	_courseToFinish;
};

#endif
