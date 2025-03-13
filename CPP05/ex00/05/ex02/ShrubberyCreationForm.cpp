/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:07:04 by akeryan           #+#    #+#             */
/*   Updated: 2025/03/13 12:29:48 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default construcor was called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): 
	AForm("Shrubbery", 145, 137)
{
	std::cout	<< "ShrubberyCreationForm construcor called: " 
				<< "object \"" << this->getName() 
				<< " with target \"" << target 
				<< "\" is attempted to be created" << std::endl;
	if (target == "") {
		throw (AForm::EmptyStringException());
	}
	this->_target = target;
	std::cout	<< "ShrubberyCreationForm object \"" << this->getName()
				<< "\" with target \"" << target << "\" is created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other) 
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
	this->_target = other.getTarget();
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout	<< "ShrubberyCreationForm destructor called, object \"" << this->getName() 
				<< "\" with target \"" << this->getTarget()
				<< "\" destroyed" << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
} 

void ShrubberyCreationForm::setTarget(const std::string target)
{
	if (target == "")
		throw (AForm::EmptyStringException());
	else
		this->setTarget(target);
}

void ShrubberyCreationForm::_execute(void) const
{
	std::string filename = this->getTarget() + "_shrubbery";
	std::string	tree = "";

	std::ofstream file(filename.c_str());
	
	if (file.is_open()) {
		file << tree;
	} else {
		std::cout << "ERROR: file failed to open in ShrubberyCreationForm::_execute()" << std::endl;
	}
	std::cout << filename << " file has been successfully created" << std::endl;
}

std::ostream &operator<<(std::ostream &osObj, const ShrubberyCreationForm &obj) {
		osObj	<< static_cast<const AForm&>(obj) 
				<< ", target: " << obj.getTarget();
	return osObj;
}