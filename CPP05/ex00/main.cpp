#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "BOB" << std::endl;
        Bureaucrat bob("Bob", 10);
        bob.decrementGrade();
        bob.decrementGrade();
        std::cout<< "Bureaucrat " << bob.getName() << " has grade " << bob.getGrade() << std::endl;
        bob.incrementGrade();
        std::cout<< "Bureaucrat " << bob.getName() << " has grade " << bob.getGrade() << std::endl;

        std::cout << "\nALICE" << std::endl;
        Bureaucrat alice("Alice", 1);
        alice.decrementGrade();
        std::cout<< "Bureaucrat " << alice.getName() << " has grade " << alice.getGrade() << std::endl;
        alice.incrementGrade();
        std::cout<< "Bureaucrat " << alice.getName() << " has grade " << alice.getGrade() << std::endl;
        alice.incrementGrade();
        std::cout<< "Bureaucrat " << alice.getName() << " has grade " << alice.getGrade() << std::endl;

        std::cout << "\nTRENT" << std::endl;
        Bureaucrat trent("Trent", -1);

        std::cout << "\nMALLORY" << std::endl;
        Bureaucrat mallory("Mallory", 151);

    }
    catch (std::exception & e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}