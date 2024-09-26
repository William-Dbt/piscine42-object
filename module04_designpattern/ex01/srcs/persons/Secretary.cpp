#include <iostream>
#include "../../includes/persons/Secretary.hpp"
#include "../../includes/forms/CourseFinishedForm.hpp"
#include "../../includes/forms/NeedCourseCreationForm.hpp"
#include "../../includes/forms/NeedMoreClassRoomForm.hpp"
#include "../../includes/forms/SubscriptionToCourseForm.hpp"
#include "../../includes/rooms/SecretarialOffice.hpp"

Form*	Secretary::createForm(FormType p_formType) {
	switch (p_formType) {
		case CourseFinished:
			return new CourseFinishedForm(CourseFinished);

		case NeedCourseCreation:
			return new NeedCourseCreationForm(NeedCourseCreation);

		case NeedMoreClassRoom:
			return new NeedMoreClassroomForm(NeedMoreClassRoom);

		case SubscriptionToCourse:
			return new SubscriptionToCourseForm(SubscriptionToCourse);

		default:
			break ;
	};
	return NULL;
}

void	Secretary::archiveForm() {
	if (!this->_currentRoom) {
		std::cerr << "[Secretary::archiveForm] ERROR: secretary isn't in a room !" << std::endl;
		return ;
	}

	if (!this->_currentRoom->isSecretarialOffice()) {
		std::cerr << "[Secretary::archiveForm] ERROR: secretary isn't in his secretarial office !" << std::endl;
		return ;
	}
	
	// SecretarialOffice* office = static_cast<SecretarialOffice*>(this->_currentRoom);

	// office->archiveForm(form); -> I think the form will be get further in the module
	std::cout << "[Secretary::archiveForm] " << this->_name << " has archived a form !" << std::endl;
}