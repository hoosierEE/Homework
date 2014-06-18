#include <vector>
#include <iostream>

// take a vector of <type> and pretty print it using operator<<
template <typename T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {

  // my original solution
  for (auto& i : v)
    os << i << ", ";
  os << "\b\b " << std::endl;

  // more idiomatic C++
  auto it = v.begin();
  while (it != v.end() - 1) {
    os << *it++ << ", ";
  }
  os << *it;

//  for (auto& i : v) {
//    if (i != *v.end()) // this line makes no difference, always true?
//      os << i << ", ";
//  }
//
  return os;
}

// template <> std::ostream& operator<< (std::ostream& os, const std::vector<char>& v) {
// // a char array may be initialized with string syntax, but it will have a trailing '\0'
//   for (auto& i : v) {
//     os << i;
//   }
//   return os;
// }

int main() {
  std::cout << "First print backspace chars at the end of each list." << std::endl;
  std::cout << "Then show the more idiomatic C++ version." << std::endl;
  // initialize some vectors
  std::vector<float> floatVector = { 1.1, 1.9, 8.2, 0.4, -1.5 };
  std::vector<int> integralVector = { 1, 10, 82, -4, 5 };
  std::vector<char> charVector = { 'h', 'e', 'l', 'l', 'o' };
  std::vector<std::string> stringVector = { "hello", "there", "world" };


  // pretty-print the vector using the overloaded '<<' operator
  std::cout << floatVector << std::endl;
  std::cout << charVector << std::endl;
  std::cout << integralVector << std::endl;
  std::cout << stringVector << std::endl;
}
