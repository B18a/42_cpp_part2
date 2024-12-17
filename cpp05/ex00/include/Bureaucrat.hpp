

#include <iostream>
#include <exception>


#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat
{
	private:
		const std::string _name;
		int		_grade;

	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);


		std::string getName(void);
		int 		getGrade(void);
		void 		increment_Grade(void);
		void		decrement_Grade(void);

/****************************************/
/*				EXCEPTIONS				*/
/****************************************/
/*
	Inheritance (: public std::exception):

    By inheriting from std::exception, the custom exception becomes 
	compatible with the standard C++ exception-handling mechanism (e.g., try-catch blocks).
    It also provides a default implementation of methods like what().
*/
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};


};
