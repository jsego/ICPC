// numeric_limits example
#include <iostream>     // std::cout
#include <limits>       // std::numeric_limits

int main () {
  std::cout << std::boolalpha;

  std::cout << "Minimum value for bool: " << std::numeric_limits<bool>::min() << '\n';
  std::cout << "Maximum value for bool: " << std::numeric_limits<bool>::max() << '\n';
  std::cout << "bool is signed: " << std::numeric_limits<bool>::is_signed << '\n';
  std::cout << "Non-sign bits in bool: " << std::numeric_limits<bool>::digits << '\n';
  std::cout << "bool has infinity: " << std::numeric_limits<bool>::has_infinity << '\n'<<std::endl;

  std::cout << "Minimum value for char: " << std::numeric_limits<char>::min() << '\n';
  std::cout << "Maximum value for char: " << std::numeric_limits<char>::max() << '\n';
  std::cout << "char is signed: " << std::numeric_limits<char>::is_signed << '\n';
  std::cout << "Non-sign bits in char: " << std::numeric_limits<char>::digits << '\n';
  std::cout << "char has infinity: " << std::numeric_limits<char>::has_infinity << '\n'<<std::endl;

  std::cout << "Minimum value for int: " << std::numeric_limits<int>::min() << '\n';
  std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
  std::cout << "int is signed: " << std::numeric_limits<int>::is_signed << '\n';
  std::cout << "Non-sign bits in int: " << std::numeric_limits<int>::digits << '\n';
  std::cout << "int has infinity: " << std::numeric_limits<int>::has_infinity << '\n'<<std::endl;

  std::cout << "Minimum value for long long: " << std::numeric_limits<long long>::min() << '\n';
  std::cout << "Maximum value for long long: " << std::numeric_limits<long long>::max() << '\n';
  std::cout << "long long is signed: " << std::numeric_limits<long long>::is_signed << '\n';
  std::cout << "Non-sign bits in long long: " << std::numeric_limits<long long>::digits << '\n';
  std::cout << "long long has infinity: " << std::numeric_limits<long long>::has_infinity << '\n'<<std::endl;
  
  std::cout << "Minimum value for float: " << std::numeric_limits<float>::min() << '\n';
  std::cout << "Maximum value for float: " << std::numeric_limits<float>::max() << '\n';
  std::cout << "float is signed: " << std::numeric_limits<float>::is_signed << '\n';
  std::cout << "Non-sign bits in float: " << std::numeric_limits<float>::digits << '\n';
  std::cout << "float has infinity: " << std::numeric_limits<float>::has_infinity << '\n'<<std::endl;


  std::cout << "Minimum value for double: " << std::numeric_limits<double>::min() << '\n';
  std::cout << "Maximum value for double: " << std::numeric_limits<double>::max() << '\n';
  std::cout << "double is signed: " << std::numeric_limits<double>::is_signed << '\n';
  std::cout << "Non-sign bits in double: " << std::numeric_limits<double>::digits << '\n';
  std::cout << "double has infinity: " << std::numeric_limits<double>::has_infinity << '\n'<<std::endl;

  std::cout << "Minimum value for long double: " << std::numeric_limits<long double>::min() << '\n';
  std::cout << "Maximum value for long double: " << std::numeric_limits<long double>::max() << '\n';
  std::cout << "long double is signed: " << std::numeric_limits<long double>::is_signed << '\n';
  std::cout << "Non-sign bits in long double: " << std::numeric_limits<long double>::digits << '\n';
  std::cout << "long double has infinity: " << std::numeric_limits<long double>::has_infinity << '\n'<<std::endl;

  return 0;
}
