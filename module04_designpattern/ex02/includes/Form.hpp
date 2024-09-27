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
			this->_isSigned = false;
		}

		virtual void	execute() = 0;

		const FormType&	getFormType() const {
			return this->_type;
		}

	protected:
		FormType	_type;
		bool		_isSigned;
};

#endif
