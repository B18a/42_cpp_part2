echo "Testing with value [0]"
echo "Result:"
./scalarconverter "0"
echo "Solution:"
echo "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n"

echo "Testing with value [nan]"
echo "Result:"
./scalarconverter "nan"
echo "Solution:"
echo "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"

echo "Testing with value [42.0f]"
echo "Result:"
./scalarconverter "42.0f"
echo "Solution:"
echo "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"

echo "Testing with value [a]"
echo "Result:"
./scalarconverter "a"
echo "Solution:"
echo "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0\n"

echo "Testing with value [z]"
echo "Result:"
./scalarconverter "z"
echo "Solution:"
echo "char: 'z'\nint: 122\nfloat: 122.0f\ndouble: 122.0\n"

echo "Testing with value [42]"
echo "Result:"
./scalarconverter "42"
echo "Solution:"
echo "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"

echo "Testing with value [-42]"
echo "Result:"
./scalarconverter "-42"
echo "Solution:"
echo "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n"

echo "Testing with value [-42.0f]"
echo "Result:"
./scalarconverter "-42.0f"
echo "Solution:"
echo "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n"

echo "Testing with value [nanf]"
echo "Result:"
./scalarconverter "nanf"
echo "Solution:"
echo "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"

echo "Testing with value [+inff]"
echo "Result:"
./scalarconverter "+inff"
echo "Solution:"
echo "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n"

echo "Testing with value [-inff]"
echo "Result:"
./scalarconverter "-inff"
echo "Solution:"
echo "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n"

# /* Test cases for double conversions */
echo "Testing with value [42.0]"
echo "Result:"
./scalarconverter "42.0"
echo "Solution:"
echo "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"

echo "Testing with value [-42.0]"
echo "Result:"
./scalarconverter "-42.0"
echo "Solution:"
echo "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n"

echo "Testing with value [+inf]"
echo "Result:"
./scalarconverter "-inf"
echo "Solution:"
echo "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n"

echo "Testing with value [-inf]"
echo "Result:"
./scalarconverter "-inf"
echo "Solution:"
echo "-inf", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n"

# /* Test cases for impossible conversions */

echo "Testing with value [hello]"
echo "Result:"
./scalarconverter "hello"
echo "Solution:"
echo "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"

echo "Testing with value [42.0a]"
echo "Result:"
./scalarconverter "42.0a"
echo "Solution:"
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
echo "Result:"
./scalarconverter "-0.0"
echo "Solution:"
echo "char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -0.0\n"

echo "Testing with value [+0.0]"
echo "Result:"
./scalarconverter "+0.0"
echo "Solution:"
echo "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n"


        # /* Test cases for hexadecimal numbers */

echo "Testing with value [0x1A]"
echo "Result:"
./scalarconverter "0x1A"
echo "Solution:"
echo "char: Non displayable\nint: 26\nfloat: 26.0f\ndouble: 26.0\n"

echo "Testing with value [1e10]"
echo "Result:"
./scalarconverter "1e10"
echo "Solution:"
echo "char: impossible\nint: impossible\nfloat: 10000000000.0f\ndouble: 10000000000.0\n"

echo "Testing with value [2.5e-3]"
echo "Result:"
./scalarconverter "2.5e-3"
echo "Solution:"
echo "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n"
   
echo "Testing with value [123abc]"
echo "Result:"
./scalarconverter "123abc"
echo "Solution:"
echo "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"
   
echo "Testing with value [!@#$%]"
echo "Result:"
./scalarconverter "!@#$%"
echo "Solution:"
echo "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"
 