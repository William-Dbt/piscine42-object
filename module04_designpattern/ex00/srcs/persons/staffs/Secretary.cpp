#include "../../../includes/persons/staffs/Secretary.hpp"
#include "../../../includes/rooms/SecretarialOffice.hpp"

Form*	Secretary::createForm(FormType p_formType) {
	switch (p_formType) {

	};
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
	std::cout << "[Secretary::archiveForm] " << this->_name << " has archived a form !" << std::endl;
}
