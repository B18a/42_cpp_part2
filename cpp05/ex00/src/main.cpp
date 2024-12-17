
#include <iostream>
#include"../include/Bureaucrat.hpp"

/****************************************************/
/*					EXEPTIONS						*/
/****************************************************/

void createBureaucrat() {
    Bureaucrat b1("Alice", 0); // Throws GradeTooHighException
}

int	main(void)
{

/****************************************************/
/*				Single Exception Check				*/
/****************************************************/

	try {
    Bureaucrat b1("Alice", 0);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

/****************************************************/
/*			Exception Check			            	*/
/****************************************************/
// First exception that is thrown stops the normal flow of
// execution and immediately looks for the nearest matching 
// catch block in the current scope.

    try {
        Bureaucrat b2("Bob", 200);
        Bureaucrat b1("Alice", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught an unknown exception: " << e.what() << std::endl;
    }


/****************************************************/
/*		 Exception get thrown to the caller			*/
/****************************************************/
    try {
        createBureaucrat();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	return (0);
}




