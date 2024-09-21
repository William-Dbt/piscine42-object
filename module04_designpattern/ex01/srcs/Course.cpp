#include <iostream>
#include "../includes/Course.hpp"

Course::Course(const std::string& p_name) {
	this->_name = p_name;
	this->_responsable = NULL;
	this->_numberOfClassToGraduate = NB_CLASS_TO_GRADUATE;
	this->_maximumNumberOfStudents = MAX_NB_STUDENTS_PER_CLASS;
}

void	Course::assign(Professor* p_professor) {
	if (!p_professor) {
		std::cerr << "[Course::assign] ERROR: invalid professor." << std::endl;
		return ;
	}
	if (this->_responsable == p_professor)
		return ;

	std::cout << "[Course::assign] The new professor for the course " << this->_name << " is " << p_professor->getName() << '!' << std::endl;
	this->_responsable = p_professor;
}

void	Course::subscribe(Student* p_student) {
	if (!p_student) {
		std::cerr << "[Course::subscribe] ERROR: invalid student." << std::endl;
		return ;
	}
	if (this->isStudentInCourse(p_student)) {
		std::cerr << "[Course::subscribe] WARNING: student is already subscribed to this course." << std::endl;
		return ;
	}
	this->_students.push_back(p_student);
}

bool	Course::isStudentInCourse(const Student* student) {
	if (this->_students.size() == 0)
		return false;

	std::vector<Student*>::iterator	it;

	for (it = this->_students.begin(); it != this->_students.end(); it++)
		if ((*it) == student)
			return true;

	return false;
}

const std::string&	Course::getName() const {
	return this->_name;
}

const Professor*	Course::getResponsable() const {
	return this->_responsable;
}
