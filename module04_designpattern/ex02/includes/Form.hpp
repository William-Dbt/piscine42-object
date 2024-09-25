#ifndef __FORM_HPP__
# define __FORM_HPP__

class	Headmaster;

enum	FormType {
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class	Form {
	public:
		Form(FormType p_formType) {
			this->_formType = p_formType;
			this->_isSigned = false;
		}

		virtual void	execute() = 0;

		const bool& isSigned() const {
			return this->_isSigned;
		}

		const FormType&	getFormType() const {
			return this->_formType;
		}

		friend class Headmaster;

	protected:
		Form() {}

		bool		_isSigned;
		FormType	_formType;
};

# include "persons/staffs/Headmaster.hpp"

#endif
