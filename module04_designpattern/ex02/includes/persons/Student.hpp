#ifndef __STUDENT_HPP__
# define __STUDENT_HPP__

# include <vector>
# include "../Person.hpp"

class	Course;
class	Classroom;

class	Student: public Person {
	public:
		Student(const std::string& name);

		void	attendClass(Classroom* classroom);
		void	exitClass();
		void	graduate(Course* course);

	private:
		Classroom*				_currentClassroom;
		std::vector<Course*>	_subscribedCourse;
};

# include "../Course.hpp"
# include "../rooms/Classroom.hpp"

#endif
