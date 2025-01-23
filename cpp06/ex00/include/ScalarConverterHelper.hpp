#include<iostream>

#ifndef SCALARCONVERTERHELPER_HPP
#define SCALARCONVERTERHELPER_HPP

	double transform_value(const std::string& value_as_string);

	bool isNegativeInfinite(const std::string& value);
	bool isPositiveInfinite(const std::string& value);
	bool isInfinite(const double& value);

	bool isNotANumber(const std::string& value);
	bool isNotANumber(const double& value);

	void printErrorMessage(const std::string message);
	void printLiteralName(const std::string name);

#endif
