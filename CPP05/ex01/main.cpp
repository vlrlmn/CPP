#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "---------------FORM CREATION---------------" << std::endl;
        Bureaucrat bob("Bob", 10);
        std::cout << bob << std::endl;
        Form form1("form1", 3, 5);
        std::cout << form1 << std::endl;
        Form form2("form2", 11, 15);
        bob.signForm(form2);

        // Negative tests
        Form form3("form3", 30, 500);
        Form form4("form4", 30, -50);
        Form form5("form5", -30, 5);
        Form form6("", 5, 5);
        
        // Form signment tests
        std::cout << std::endl << "---------------ALICE SIGNING FORM (enough grade)---------------" << std::endl;
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        std::cout << std::endl << "---BEFORE SIGNMENT" << std::endl;
        std::cout << form1 << std::endl;
        alice.signForm(form1);
        std::cout << std::endl << "---AFTER SIGNMENT" << std::endl;
        std::cout << form1 << std::endl;
        alice.signForm(form1);
        std::cout << std::endl << "---------------BOB SIGNING FORM (not enough grade)---------------" << std::endl;
        bob.signForm(form1);
    }
    catch (std::exception & e)
    {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }
}