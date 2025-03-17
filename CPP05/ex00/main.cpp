#include "Bureaucrat.hpp"

int main()
{
    try
    {
        //Valid tests
        std::cout << "BOB" << std::endl;
        Bureaucrat bob("Bob", 10);
        bob.decrementGrade();
        bob.decrementGrade();
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        // Invalid test case to increment and decrement
        std::cout << std::endl << "ALICE" << std::endl;
        Bureaucrat alice("Alice", 1);
        alice.decrementGrade();
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;

        // Invalid test case too high
        std::cout << std::endl << "TRENT" << std::endl;
        Bureaucrat trent("Trent", -1);
        std::cout << trent << std::endl;

        // Invalid test case too low
        std::cout << std::endl << "MALLORY" << std::endl;
        Bureaucrat mallory("Mallory", 151);

    }
    catch (std::exception & e)
    {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }
}