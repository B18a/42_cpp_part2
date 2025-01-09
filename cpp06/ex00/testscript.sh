echo "Testing with value [0]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "0"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n"

echo "Testing with value [nan]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "nan"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"

echo "Testing with value [42.0f]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "42.0f"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"

echo "Testing with value [a]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "'a'"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0\n"

echo "Testing with value [z]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "'z'"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: 'z'\nint: 122\nfloat: 122.0f\ndouble: 122.0\n"

echo "Testing with value [42]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "42"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"

echo "Testing with value [-42]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "-42"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n"

echo "Testing with value [-42.0f]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "-42.0f"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n"

echo "Testing with value [nanf]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "nanf"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"

echo "Testing with value [+inff]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "+inff"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n"

echo "Testing with value [-inff]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "-inff"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n"

# /* Test cases for double conversions */
echo "Testing with value [42.0]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "42.0"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"

echo "Testing with value [-42.0]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "-42.0"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n"

echo "Testing with value [+inf]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "-inf"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n"

echo "Testing with value [-inf]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "-inf"
printf "\033[0;35mSolution:\n\033[0m"
echo "-inf", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n"

# /* Test cases for impossible conversions */

echo "Testing with value [hello]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "hello"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"

echo "Testing with value [42.0a]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "42.0a"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"


# /* Test cases for INT_MIN, INT_MAX, FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX */




        # std::cout << CYAN << "INT_MIN: " << INT_MIN << NC << std::endl;
        # testConversion(toString(INT_MIN), "char: impossible\nint: " + toString(INT_MIN) + "\nfloat: " + toString(static_cast<float>(INT_MIN)) + "f\ndouble: " + toString(static_cast<double>(INT_MIN)) + "\n");
        
        # std::cout << CYAN << "INT_MAX: " << INT_MAX << NC << std::endl;
        # testConversion(toString(INT_MAX), "char: impossible\nint: " + toString(INT_MAX) + "\nfloat: " + toString(static_cast<float>(INT_MAX)) + "f\ndouble: " + toString(static_cast<double>(INT_MAX)) + "\n");

        # std::cout << CYAN << "FLT_MIN: " << FLT_MIN << NC << std::endl;
        # testConversion(toString(FLT_MIN), "char: Non displayable\nint: 0\nfloat: " + toString(FLT_MIN) + "f\ndouble: " + toString(static_cast<double>(FLT_MIN)) + "\n");
        
        # std::cout << CYAN << "FLT_MAX: " << FLT_MAX << NC << std::endl;
        # testConversion(toString(FLT_MAX), "char: impossible\nint: impossible\nfloat: " + toString(FLT_MAX) + "f\ndouble: " + toString(static_cast<double>(FLT_MAX)) + "\n");

        # std::cout << CYAN << "DBL_MIN: " << DBL_MIN << NC << std::endl;
        # testConversion(toString(DBL_MIN), "char: Non displayable\nint: 0\nfloat: " + toString(static_cast<float>(DBL_MIN)) + "f\ndouble: " + toString(DBL_MIN) + "\n");
        
        # std::cout << CYAN << "DBL_MAX: " << DBL_MAX << NC << std::endl;
        # testConversion(toString(DBL_MAX), "char: impossible\nint: impossible\nfloat: +" + toString(static_cast<float>(DBL_MAX)) + "f\ndouble: " + toString(DBL_MAX) + "\n");

        # /* Test case for positive negative floating point digit 0 */

echo "Testing with value [-0.0]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "-0.0"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -0.0\n"

echo "Testing with value [+0.0]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "+0.0"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n"


        # /* Test cases for hexadecimal numbers */

echo "Testing with value [0x1A]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "0x1A"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: Non displayable\nint: 26\nfloat: 26.0f\ndouble: 26.0\n"

echo "Testing with value [1e10]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "1e10"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: 10000000000.0f\ndouble: 10000000000.0\n"

echo "Testing with value [2.5e-3]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "2.5e-3"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n"
   
echo "Testing with value [123abc]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "123abc"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"
   
echo "Testing with value [!@#$%]"
printf "\033[0;35mResult:\n\033[0m"
./scalarconverter "!@#$%"
printf "\033[0;35mSolution:\n\033[0m"
echo "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"
 