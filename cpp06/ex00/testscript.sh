echo "Testing with value [a]"
./scalarconverter "'a'"
echo ""
echo "Testing with value [122]"
./scalarconverter 122
echo ""
echo "Testing with value [-inff]"
./scalarconverter -inff
echo ""
echo "Testing with value [0]"
./scalarconverter 0
echo ""
echo "Testing with value ['!']"
./scalarconverter "'!'"
echo ""
echo "Testing with value [33]"
./scalarconverter 33
# echo ""
# echo "Testing with value [2147483648.0]"
# ./scalarconverter "2147483648.0"