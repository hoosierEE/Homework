#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

template <typename T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& v)
{ // pretty-print a vector using operator<<
  for (auto& i : v)
    i == *v.begin() ? os << i : os << ", " << i;
  return os;
}

int elems = 100;

struct randomGenerator {
  randomGenerator() {};
  double operator()() { return rand()/(double)RAND_MAX;  }
};

std::vector<double> randVec(std::vector<double> x) {
  x.reserve(elems);
  std::generate_n(std::back_inserter(x), elems, randomGenerator());
  return x;
}

int main() {
  srand(std::time(0));
  std::vector<double> a;
  std::vector<double> b;
  a = randVec(a);
  b = randVec(b);

  std::vector<double> m(elems * elems);
  for (int i = 0; i < m.size(); i++)
    for (int j = 0; j < a.size(); j++)
      m[i] = a[i] * b[j];

  std::cout << m << std::endl;
}
