#include <iostream>
#include "../../includes/forms/CourseFinishedForm.hpp"
#include "../../includes/lists/CourseList.hpp"

CourseFinishedForm::CourseFinishedForm(FormType type): Form(type) {
	this->_courseToFinish = NULL;
}

void	CourseFinishedForm::assignCourse(Course* course) {
	if (!course) {
		std::cerr << "An error occured during course assigment." << std::endl;
		return ;
	}
	this->_courseToFinish = course;
}

static void	endCourse(Course* course, std::vector<Course*>::iterator itInList, std::vector<Course*>& list) {
	Professor*	prof = course->getResponsable();

	prof->closeCourse();
	list.erase(itInList);
}

void	CourseFinishedForm::execute() {
	if (!this->_isSigned) {
		std::cerr << "[CourseFinishedForm::execute()] the form hasn't been signed yet, it can't be executed." << std::endl;
		return ;
	}
	if (!this->_courseToFinish) {
		std::cerr << "[CourseFinishedForm::execute()] can't execute the form properly, no course has been specified.\n";
		std::cerr << "Please, use the function CourseFinishedForm::assignCourse() to assign one before executing the form." << std::endl;
		return ;
	}
	CourseList*	courseList = Singleton<CourseList>::getInstance();

	if (!courseList)
		return ;

	std::vector<Course*>	courses = courseList->getList();

	if (courses.size() == 0) {
		std::cerr << "[CourseFinishedForm::execute()] it appears that the list of courses is empty, please fill the list or create one." << std::endl;
		return ;
	}

	std::vector<Course*>::iterator	it;

	for (it = courses.begin(); it != courses.end(); it++) {
		if ((*it) == this->_courseToFinish) {
			endCourse(this->_courseToFinish, it, courses);
			break ;
		}
	}
	if (it == courses.end())
		std::cerr << "[CourseFinishedForm::execute()] the course isn't registered in the list of the school courses. The form can't be executed." << std::endl;
}
