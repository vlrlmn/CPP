#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "BOB" << std::endl;
        Bureaucrat bob("Bob", 10);
        bob.decrementGrade();
        bob.decrementGrade();
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        std::cout << "\nALICE" << std::endl;
        Bureaucrat alice("Alice", 1);
        alice.decrementGrade();
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;

        std::cout << "\nTRENT" << std::endl;
        Bureaucrat trent("Trent", -1);
        std::cout << trent << std::endl;


        std::cout << "\nMALLORY" << std::endl;
        Bureaucrat mallory("Mallory", 151);

    }
    catch (std::exception & e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}