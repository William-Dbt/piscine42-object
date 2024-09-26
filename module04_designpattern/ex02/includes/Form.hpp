#ifndef __FORM_HPP__
# define __FORM_HPP__

enum	FormType {
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class	Form {
	public:
		Form(FormType type) {
			this->_type = type;
		}

		virtual void	execute() = 0;

		const FormType&	getFormType() const {
			return this->_type;
		}

	private:
		FormType	_type;
};

#endif
