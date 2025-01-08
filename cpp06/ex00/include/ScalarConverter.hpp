

#include<iostream>

#pragma once

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter(void);

		ScalarConverter& operator=(const ScalarConverter& other);



		static double transform_value(const std::string& value_as_string);


		static float ConvertToFloat(const std::string& value);
		static float ConvertToDouble(const std::string& value);
		static float ConvertToInt(const std::string& value);

		static bool isFloat(const std::string& value);
		static bool isDouble(const std::string& value);
		static bool isInt(const std::string& value);

		static bool isNegativeInfinite(const std::string& value);
		static bool isPositiveInfinite(const std::string& value);
		static bool isUndefined(const std::string& value);


		static void printAsFloat(const float& value);




	public:
		static void convert(const std::string& value_as_string);
	
};


#endif







/*


https://www.geeksforgeeks.org/static-keyword-cpp/

Static Variables in a FUNCTION
In a function, when a variable is declared as static, space for it gets allocated for the lifetime of the program.
Even if the function is called multiple times.

Static Data Member in a CLASS
As the variables declared as static are initialized only once as they are allocated space in separate static storage so,
the static member variables in a class are shared by the objects. There cannot be multiple copies of the same static variables for different objects.
Also because of this reason static variables cannot be initialized using constructors

So, a static variable inside a class should be initialized explicitly by the user using the class name and scope resolution operator outside the class 

Static Member Functions in a Class
Static member functions are allowed to access only the static data members or other static member functions,
they cannot access the non-static data members or member functions of the class. 



#include <iostream>
using namespace std;

class Example {
private:
    static int count; // Private static variable

public:
    // Static member function to access and modify the private static variable
    static void setCount(int value) {
        count = value;
    }

    static int getCount() {
        return count;
    }
};

// Definition and initialization of the static variable
int Example::count = 0;

int main() {
    // Accessing private static variable via static member functions
    Example::setCount(10); 
    cout << "Count: " << Example::getCount() << endl;

    return 0;
}
Key Points:
Private Access Control:

The private static variable count is inaccessible directly outside the class.
You must use static member functions like setCount and getCount to interact with it.
Encapsulation:

Declaring the static variable as private ensures encapsulation, preventing direct modifications from outside the class.




*/
