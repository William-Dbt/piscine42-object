#include "../../../includes/persons/staffs/Secretary.hpp"
#include "../../../includes/rooms/SecretarialOffice.hpp"

#include "../../../includes/forms/CourseFinishedForm.hpp"
#include "../../../includes/forms/NeedCourseCreationForm.hpp"
#include "../../../includes/forms/NeedMoreClassRoomForm.hpp"
#include "../../../includes/forms/SubscriptionToCourseForm.hpp"

Form*	Secretary::createForm(FormType p_formType) {
	switch (p_formType) {
		case CourseFinished:
			return new CourseFinishedForm(CourseFinished);

		case NeedCourseCreation:
			return new NeedCourseCreationForm(NeedCourseCreation);

		case NeedMoreClassRoom:
			return new NeedMoreClassRoomForm(NeedMoreClassRoom);

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

	SecretarialOffice* office = dynamic_cast<SecretarialOffice*>(this->_currentRoom);

	if (!office) {
		std::cerr << "[Secretary::archiveForm] ERROR: secretary isn't in his secretarial office !" << std::endl;
		return ;
	}
	// office->_archivedForms.push_back(form);
	std::cout << "[Secretary::archiveForm] " << this->_name << " has archived a form !" << std::endl;
}
