#ifndef __COURSE_HPP__
# define __COURSE_HPP__

# define NB_CLASS_TO_GRADUATE		15
# define MAX_NB_STUDENTS_PER_CLASS	24

# include <string>
# include <vector>
# include "persons/staffs/Professor.hpp"
# include "persons/Student.hpp"

class	Course {
	public:
		Course(const std::string& p_name);

		void	assign(Professor* p_professor);
		void	subscribe(Student* p_student);

		bool	isStudentInCourse(const Student* student);

		const Professor*	getResponsable() const;

	private:
		std::string				_name;
		Professor*				_responsable;
		std::vector<Student*>	_students;

		int	_numberOfClassToGraduate;
		int	_maximumNumberOfStudents;
};

#endif
