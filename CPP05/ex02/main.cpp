#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        std::cout << "FORM CREATION" << std::endl;
        // Bureaucrat bob("Bob", 10);
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}