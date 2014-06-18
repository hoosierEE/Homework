#include <vector>
#include <iostream>

// take a vector of <type> and pretty print it using operator<<
template <typename T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {
  for (auto& i : v) {
    os << i << ",";
  }
  os << "\b ";
  return os;
}
template <> std::ostream& operator<< (std::ostream& os, const std::vector<char>& v) {
// for some reason an array of chars prints an extra trailing comma
  for (auto& i : v) {
    os << i;
  }
  return os;
}


int main() {
  // initialize some vectors
  // floats
  static const float floatArray[] = { 1.1, 10, 82, 4, 5 };
  std::vector<float> floatVector
    ( floatArray
    , floatArray + sizeof(floatArray) / sizeof(floatArray[0])
    );

  // integers
  static const int integralArray[] = { 1, 10, 82, 4, 5 };
  std::vector<int> integralVector
    ( integralArray
    , integralArray + sizeof(integralArray) / sizeof(integralArray[0])
    );

  // chars
  static const char charArray[] = { "hello" };
  std::vector<char> charVector
    ( charArray
    , charArray+sizeof(charArray) / sizeof(charArray[0])
    );

  // pretty-print the vector using the overloaded '<<' operator
  std::cout << "a vector of floats: " << floatVector << std::endl;
  std::cout << "a vector of chars (string): " << charVector << std::endl;
  std::cout << "a vector of integers: " << integralVector << std::endl;
}
