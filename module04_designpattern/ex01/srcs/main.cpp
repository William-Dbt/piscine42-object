#include <iostream>
#include <thread>
#include <unistd.h>
#include "../includes/Singleton.hpp"
#include "../includes/lists/StudentList.hpp"
#include "../includes/lists/StaffList.hpp"
#include "../includes/lists/RoomList.hpp"
#include "../includes/lists/CourseList.hpp"

void	handleListThread() {
	StudentList*	studentList = Singleton<StudentList>::getInstance();

	(void)studentList;
}

int	main() {
	{
		std::cout << "----- StudentList -----" << std::endl;

		StudentList*	studentList = Singleton<StudentList>::getInstance();

		Student*	student0 = new Student("Toto");
		Student*	student1 = new Student("Titi");

		studentList->add(student0);
		studentList->add(student1);

		std::vector<Student*> list = studentList->getList();
		std::cout << "List size : " << list.size() << '\n';
		std::cout << list[0]->getName() << '\n';
		std::cout << list[1]->getName() << '\n';
		std::cout << std::boolalpha << "Is student1 in list ? (Titi) " << studentList->isInList(student1) << std::endl;
		studentList->remove(student0);
		list = studentList->getList();
		std::cout << "List size after removing item : " << list.size() << '\n' << std::endl;

		std::cout << "Create new studentList to show the ptr and informations are the same" << std::endl;
		StudentList*	studentList2 = Singleton<StudentList>::getInstance();

		list = studentList2->getList();
		std::cout << "List size : " << list.size() << '\n';

		std::cout << "---------------------\n" << std::endl;
	}
	{
		std::cout << "----- StaffList -----" << std::endl;

		StaffList*	staffList = Singleton<StaffList>::getInstance();

		Staff*	staff0 = new Staff("Toto");
		Staff*	staff1 = new Staff("Titi");

		staffList->add(staff0);
		staffList->add(staff1);

		std::vector<Staff*> list = staffList->getList();
		std::cout << "List size : " << list.size() << '\n';
		std::cout << list[0]->getName() << '\n';
		std::cout << list[1]->getName() << '\n';
		std::cout << std::boolalpha << "Is staff1 in list ? (Titi) " << staffList->isInList(staff1) << std::endl;
		staffList->remove(staff0);
		list = staffList->getList();
		std::cout << "List size after removing item : " << list.size() << '\n' << std::endl;

		std::cout << "Create new staffList to show the ptr and informations are the same" << std::endl;
		StaffList*	staffList2 = Singleton<StaffList>::getInstance();

		list = staffList2->getList();
		std::cout << "List size : " << list.size() << '\n';

		std::cout << "---------------------\n" << std::endl;
	}
	{
		std::cout << "----- RoomList -----" << std::endl;

		RoomList*	roomList = Singleton<RoomList>::getInstance();

		Room*	room0 = new Room();
		Room*	room1 = new Room();

		roomList->add(room0);
		roomList->add(room1);

		std::vector<Room*> list = roomList->getList();
		std::cout << "List size : " << list.size() << '\n';
		std::cout << list[0]->getId() << '\n';
		std::cout << list[1]->getId() << '\n';
		std::cout << std::boolalpha << "Is room1 in list ? (id : 1) " << roomList->isInList(room1) << std::endl;
		roomList->remove(room0);
		list = roomList->getList();
		std::cout << "List size after removing item : " << list.size() << '\n' << std::endl;

		std::cout << "Create new roomList to show the ptr and informations are the same" << std::endl;
		RoomList*	roomList2 = Singleton<RoomList>::getInstance();

		list = roomList2->getList();
		std::cout << "List size : " << list.size() << '\n';

		std::cout << "---------------------\n" << std::endl;
	}
	{
		std::cout << "----- CourseList -----" << std::endl;

		CourseList*	courseList = Singleton<CourseList>::getInstance();

		Course*	course0 = new Course("Mathématiques");
		Course*	course1 = new Course("Sciences");

		courseList->add(course0);
		courseList->add(course1);

		std::vector<Course*> list = courseList->getList();
		std::cout << "List size : " << list.size() << '\n';
		std::cout << list[0]->getName() << '\n';
		std::cout << list[1]->getName() << '\n';
		std::cout << std::boolalpha << "Is course1 in list ? (Sciences) " << courseList->isInList(course1) << std::endl;
		courseList->remove(course0);
		list = courseList->getList();
		std::cout << "List size after removing item : " << list.size() << '\n' << std::endl;

		std::cout << "Create new courseList to show the ptr and informations are the same" << std::endl;
		CourseList*	courseList2 = Singleton<CourseList>::getInstance();

		list = courseList2->getList();
		std::cout << "List size : " << list.size() << '\n';

		std::cout << "---------------------\n" << std::endl;
	}
	{
		std::cout << "----- ThreadSafe Tests -----" << std::endl;

		std::thread	th0(handleListThread);
		std::thread	th1(handleListThread);
		std::thread	th2(handleListThread);
		std::thread	th3(handleListThread);

		th0.join();
		th1.join();
		th2.join();
		th3.join();

		std::cout << "---------------------" << std::endl;
	}
}