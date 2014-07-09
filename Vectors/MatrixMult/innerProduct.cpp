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

struct gen_rand {
  gen_rand() {};
  double operator()() { return rand()/(double)RAND_MAX;  }
};

std::vector<double> randVec(std::vector<double> x) {
  x.reserve(elems);
  std::generate_n(std::back_inserter(x), elems, gen_rand());
  return x;
}

int main() {
  srand(std::time(0));
  std::vector<double> a;
  std::vector<double> b;
  //std::cout << randVec(x) << std::endl;
  //std::cout << randVec(y) << std::endl;

  // TODO: create matrix whose rows are a * (all of) b
  std::vector<std::vector<double>> m;

}
