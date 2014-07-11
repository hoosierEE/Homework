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

struct randomGenerator {
  randomGenerator() {};
  double operator()() { return rand()/(double)RAND_MAX;  }
};

std::vector<double> randVec(std::vector<double> x, int elems) {
  x.reserve(elems);
  std::generate_n(std::back_inserter(x), elems, randomGenerator());
  return x;
}

int main(int argc, char* argv[]) {
  srand(std::time(0));
  int elems = std::atoi(argv[1]);
  // create a matrix of random values
  std::vector<double> m(elems * elems); // actually this is a vector of length (N*N)
  std::vector<double> a;
  std::vector<double> b;
  a = randVec(a, elems);
  b = randVec(b, elems);
  std::vector<double> r(elems, 0); // to store the result

  for (auto i = 0; i < m.size(); i++)
    for (auto j = 0; j < a.size(); j++)
      m[i] = a[j] * b[i];

  // do inner product
  for (auto i = 0; i < a.size(); i++)
    for (auto j = 0; j < b.size(); j++)
      r[i] += a[i] * m[i + j];  // swap loop order

  //std::cout << r << std::endl;
}
