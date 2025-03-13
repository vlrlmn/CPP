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
	}
}

std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &sh) {
	stream << 
}