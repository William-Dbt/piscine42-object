#include "../../includes/persons/Student.hpp"

Student::Student(const std::string& name): Person(name) {
	this->_currentClassroom = NULL;
}

void	Student::attendClass(Classroom* classroom) {
	if (!classroom)
		return ;

	if (this->_currentClassroom)
		this->exitClass();

	if (classroom->canEnter(this)) {
		classroom->enter(this);
		this->_currentClassroom = classroom;
	}
}

void	Student::exitClass() {
	if (!this->_currentClassroom)
		return ;

	this->_currentClassroom->exit(this);
	this->_currentClassroom = NULL;
}

void	Student::graduate(Course* course) {
	if (!course)
		return ;

	std::cout << "Student " << this->_name << " has been graduated from course " << course->getName() << std::endl;
}
