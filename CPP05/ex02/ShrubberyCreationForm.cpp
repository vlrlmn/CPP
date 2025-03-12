#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Example", 145, 143){
	std::cout << "Default constructor Shrubbery Creation Form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): _target(target) {
	std::cout << "Parametrized constructor Shrubbery Creation Form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) {

}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original) {
	std::cout << "Copy assignment operator Shrubbery Creation Form" << std::endl;
	if (this != &original) {
		AForm::operator=(original);
		this->_target = original.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "Destructor called Shrubbery Creation Form" <<std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}
void ShrubberyCreationForm::setTarget(std::string target) {
	this->_target = target;
}

void ShrubberyCreationForm::_execute(void) const {
	std::string filename = this->getTarget() + "_shrubbery";
	std::string tree = "\
               ,@@@@@@@,
       ,,,.   ,@@@@@@&@@,  .oo8888o.
    ,&@@&%&&%,@@@@@&@@@@@@,8888&88&8o
   ,%&&%&&%&&%,@@@&@@@/@@@88&88888/88'
   %&&%&%&/%&&%@@&@@/ /@@@88888&88888'
   %&&%/ %&&&@@& V /@@' `88|8 `/88@8'
   `&%\' ` /%&'    |.|       \' '/8'
       |o|        | |         | |
       |.|        | |         | |
  \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_\n";

  std::ofstream file(filename.c_str());
}