#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

template <typename T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& v)
{ // pretty-print a vector using operator<<
  for (auto& i : v)
    i == *v.begin() ? os << i : os << " " << i;
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

  std::vector<double> r(elems, 0); // to store the result

  // create a matrix of random values
  std::vector<double> m(elems * elems); // actually this is a vector of length (N*N)
  for (auto i = 0; i < m.size(); i++)
    for (auto j = 0; j < a.size(); j++)
      m[i] = a[i] * b[j];

  // do inner product
  for (auto i = 0; i < a.size(); i++)
    for (auto j = 0; j < b.size(); j++)
      r[i] += a[j] * m[i + j];


  std::cout << r << std::endl;
}
