#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 143){
	std::cout << "Default constructor Shrubbery Creation Form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("Shrubbery", 145, 137) {
	std::cout << "Parametrized constructor Shrubbery Creation Form" << std::endl;
	if (target == "")
		throw(AForm::EmptyNameException());
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original): AForm(original) {
	std::cout << "Copy Constructor Shrubbery Creation Form" << std::endl;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original) {
	std::cout << "Copy assignment operator Shrubbery Creation Form" << std::endl;
	if (this != &original) {
		AForm::operator=(original);
		this->_target = original.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor called Shrubbery Creation Form" <<std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::setTarget(std::string target) {
	if (target == "")
		throw (AForm::EmptyNameException());
	else
		this->_target = target;
}
void ShrubberyCreationForm::_execute() const {
    std::string filename = this->getTarget() + "_shrubbery";
    std::string tree = "\
                ,@@@@@@@,\n\
        ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
     ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
    ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
    %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
    %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
    `&%\\ ` /%&'    |.|        \\ '|8'\n\
        |o|        | |         | |\n\
        |.|        | |         | |\n\
 \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

    std::ofstream file(filename.c_str());

    if (file.is_open()) {
        file << tree;
        file.close();
        std::cout << "Shrubbery created at " << filename << std::endl;
    } else {
        std::cout << "Failed to open file " << filename << std::endl;
    }
}
