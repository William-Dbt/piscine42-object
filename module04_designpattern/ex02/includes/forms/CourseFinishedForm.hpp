#ifndef __COURSEFINISHEDFORM_HPP__
# define __COURSEFINISHEDFORM_HPP__

# include "../Form.hpp"

class	CourseFinishedForm: public Form {
	public:
		CourseFinishedForm(FormType type): Form(type) {}

		void	execute() {}
};

#endif
