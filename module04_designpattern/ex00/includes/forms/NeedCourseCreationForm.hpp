#ifndef __NEEDCOURSECREATIONFORM_HPP__
# define __NEEDCOURSECREATIONFORM_HPP__

# include "../Form.hpp"

class	NeedCourseCreationForm: public Form {
	public:
		NeedCourseCreationForm(FormType type): Form(type) {}

		void	execute() {}
};

#endif
