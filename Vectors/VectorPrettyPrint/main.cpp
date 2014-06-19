#include <vector>
#include <iostream>

// take a vector of <type> and pretty print it using operator<<
template <typename T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {

  // first attempt
  for (auto& i : v)
      os << i << ", ";
  os << "\b\b ";

  os<<"\n";

  // second attempt
  os << v.front();
  for (const auto& i : v) {
    if (i != *v.begin())
      os << ", " << i;
  }

  os<<"\n";

  // terse
  for (auto& i : v)
    i == *v.begin() ? os << i : os << ", " << i;

  os<<"\n";

  // more idiomatic C++
  auto it = v.begin();
  while (it != v.end() - 1)
    os << *it++ << ", ";
  os << *it;

  os<<"\n";

  auto itr = v.begin();
  os << *itr++;
  while(itr != v.end())
    os << ", " << *itr++;

  return os;
}

int main() {
  // initialize some vectors
  std::vector<float> floatVector = { 1.1, 1.9, 8.2, 0.4, -1.5, };
  std::vector<int> integralVector = { 1, 10, 82, -4, 5 };
  std::vector<char> charVector = { 'h', 'e', 'l', 'l', 'o' };
  std::vector<std::string> stringVector = { "hello", "there", "world" };

  int num = 0;

  // pretty-print the vector using the overloaded 'operator<<'
  std::cout << floatVector << std::endl;
  std::cout << charVector << std::endl;
  std::cout << integralVector << std::endl;
  std::cout << stringVector << std::endl;
}
