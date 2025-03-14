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
				   $$\n\
			     & && &\n\
			  &&  & && &&\n\
			&&& &&  & && &&\n\
		 & &--&-|& ()|- @, &&\n\
		&--(-&-&||-& -_-)_&-_&\n\
	  &() &--&|()|-&-- '% & ()\n\
	  &_-_&&_- |& |&&-&__%_-_& &&\n\
	 &&   && & &| &| -& & % ()& -&&\n\
	 ()&_---()&-&-|&&-&&--%---()~\n\
	             -|||\n\
				  |||\n\
				  |||\n\
				  |||\n";

	std::ofstream file(filename.c_str());

	if (file.is_open()) {
		file << tree;
	} else {
		std::cout << "Failed to open file" << std::endl;
	}
}

