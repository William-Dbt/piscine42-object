#include <iostream>
#include "../../includes/forms/CourseFinishedForm.hpp"

void	CourseFinishedForm::execute() {
	if (!_course) {
		std::cout << "[CourseFinishedForm] no course assigned to the form, please use CourseFinishedForm::setCourse() method to assign one." << std::endl;
		return ;
	}
	if (!this->_isSigned) {
		std::cout << "[CourseFinishedForm] a form need to be signed by headmaster before it can be executed." << std::endl;
		return ;
	}

	std::cout << "[CourseFinishedForm] the course " << this->_course->_name << " is now finished. The student list will be cleared." << std::endl;
	this->_course->_responsable = NULL;
	this->_course->_students.clear();
}
