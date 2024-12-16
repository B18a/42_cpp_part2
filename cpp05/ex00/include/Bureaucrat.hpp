

# include <iostream>
#include <exception>


#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat
{
	public:
		Bureaucrat(void);
		~Bureaucrat(void);


		std::string getName(void);
		int 		getGrade(void);
		bool 		setGrade(int newGrade);
		int 		increment_Grade(void);
		int 		decrement_Grade(void);

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/
/*
	Inheritance (: public std::exception):

    By inheriting from std::exception, the custom exception becomes compatible with the standard C++ exception-handling mechanism (e.g., try-catch blocks).
    It also provides a default implementation of methods like what().
*/
		class GradeTooHighException : public std::exception
		{
			public:
				// virtual const char *what() const throw();
				virtual const char *what() const noexcept;

		};
		class GradeTooLowException : public std::exception
		{
			public:
				// virtual const char *what() const throw();
				virtual const char *what() const noexcept;
		};

	private:
		const std::string _name;
		int		_grade;

}
