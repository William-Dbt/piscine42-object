#ifndef __STUDENT_HPP__
# define __STUDENT_HPP__

# include <vector>
# include "../Person.hpp"
# include "../rooms/Classroom.hpp"

class	Course;

class	Student: public Person {
	public:
		void	attendClass(Classroom* p_classroom);
		void	exitClass();
		void	graduate(Course* p_course);

	private:
		std::vector<Course*>	_subscribedCourse;
};

# include "../Course.hpp"

#endif
