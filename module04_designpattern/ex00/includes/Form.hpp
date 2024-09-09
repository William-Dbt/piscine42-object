#ifndef __FORM_HPP__
# define __FORM_HPP__

enum class	FormType {
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class	Form {
	public:
		Form(FormType p_formType) {
			this->_formType = p_formType;
		}

		virtual void	execute() = 0;

	protected:
		Form() {}

		FormType	_formType;
};

#endif
