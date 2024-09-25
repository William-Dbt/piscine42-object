#include <iostream>
#include "../includes/persons/staffs/Headmaster.hpp"
#include "../includes/persons/staffs/Secretary.hpp"
#include "../includes/Course.hpp"
#include "../includes/persons/staffs/Professor.hpp"
#include "../includes/persons/Student.hpp"
#include "../includes/forms/CourseFinishedForm.hpp"

int	main() {
	std::cout << "Create a secretary and a headmaster that will manage our forms :\n";
	Headmaster*	headmaster = new Headmaster("Victor");
	Secretary*	secretary = new Secretary("Huguette");

	std::cout << "- Headmaster name : " << headmaster->getName() << '\n';
	std::cout << "- Secretary name : " << secretary->getName() << "\n\n";

	{
		std::cout << "----- CourseFinishedForm -----" << std::endl;

		std::cout << "Create course and fill the course with students and responsable\n" << std::endl;

		Course*		course = new Course("Mathématiques");
		Professor*	professor = new Professor("Toto");

		std::cout << "- Course name : " << course->getName() << '\n';
		course->assign(professor);

		Student*	student0 = new Student("Toto");
		Student*	student1 = new Student("Titi");
		Student*	student2 = new Student("Tutu");
		Student*	student3 = new Student("Tete");

		course->subscribe(student0);
		course->subscribe(student1);
		course->subscribe(student2);
		course->subscribe(student3);

		std::vector<Student*>	students = course->getStudentsList();

		std::cout << "- Responsable : " << course->getResponsable()->getName() << '\n';
		std::cout << "- Students list size : " << students.size() << "\n\n";

		std::cout << "The course has been completed for all students, it must be finished now. Let's fill a request for the secretary\n";

		CourseFinishedForm* courseForm = dynamic_cast<CourseFinishedForm*>(secretary->createForm(CourseFinished));

		std::cout << "Let's fill the form with our course" << std::endl;
		courseForm->setCourse(course);
		std::cout << "- Course : " << courseForm->getCourse()->getName() << '\n';
		std::cout << "- isSigned : " << std::boolalpha << courseForm->isSigned() << "\n\n";

		std::cout << "Let's close the course by executing the form : \n";
		courseForm->execute();

		std::cout << "\nLet's sign the form by the headmaster\n";
		headmaster->sign(courseForm);

		std::cout << "--------------------\n" << std::endl;
	}
}
