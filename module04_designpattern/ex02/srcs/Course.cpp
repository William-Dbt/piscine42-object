#include <iostream>
#include "../includes/Course.hpp"

Course::Course(const std::string& name) {
	this->_name = name;
	this->_responsable = NULL;

	this->_numberOfClassToGraduate = 10;
	this->_maximumNumberOfStudents = 22;
}

void	Course::assign(Professor* professor) {
	if (!professor) {
		this->_responsable = NULL;
		return ;
	}
	if (this->_responsable) {
		if (this->_responsable == professor)
			return ;

		this->_responsable->assignCourse(NULL);
	}

	Course*	currentProfessorCourse = professor->getCurrentCourse();

	if (currentProfessorCourse && currentProfessorCourse != this) {
		professor->getCurrentCourse()->assign(NULL);
		professor->assignCourse(this);
		this->_responsable = professor;
	}
}

void	Course::subscribe(Student* student) {
	if (!student)
		return ;

	if ((int)this->_students.size() == this->_maximumNumberOfStudents) {
		std::cout << "Can't subscribe more student for the course " << this->_name << ". The course is full." << std::endl;
		return ;
	}
	this->_students.push_back(student);
}

const std::string&	Course::getName() const {
	return this->_name;
}

Professor*	Course::getResponsable() const {
	return this->_responsable;
}
