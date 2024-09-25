#ifndef __STUDENTLIST_HPP__
# define __STUDENTLIST_HPP__

# include "Singleton.hpp"
# include "List.hpp"
# include "persons/Student.hpp"

class	StudentList : public Singleton<StudentList>, public List<Student> {};

#endif
