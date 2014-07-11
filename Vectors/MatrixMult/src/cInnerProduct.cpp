#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

//template <typename T>
//std::ostream& operator<< (std::ostream& os, const std::vector<T>& v)
// seems to run slightly faster without the template, not sure though.
std::ostream& operator<< (std::ostream& os, const std::vector<double>& v)
{ // pretty-print a vector using operator<<
  for (auto& i : v)
    i == *v.begin() ? os << i : os << " " << i;
  return os;
}

struct randomGenerator
{ // until I did this, it would always output the same random sequence
  randomGenerator() {};
  double operator()() { return rand()/(double)RAND_MAX;  }
};

std::vector<double> randVec(std::vector<double> &x, int elems)
{ // return a random vector
  x.reserve(elems);
  std::generate_n(std::back_inserter(x), elems, randomGenerator());
  return x;
}

int main(int argc, char* argv[])
{

  srand(std::time(0));
  int elems = std::atoi(argv[1]);
  std::vector<double> m(elems * elems); // actually this is a vector of length (N*N)
  std::vector<double> a;
  std::vector<double> b;
  std::vector<double> r(elems, 0); // to store the result

  // put random values in a and b
  a = randVec(a, elems);
  b = randVec(b, elems);

  // build random matrix from the two random vectors
  for (auto i = 0; i < m.size(); i++)
    for (auto j = 0; j < a.size(); j++)
      m[i] = a[i] * b[j];

  // do inner product
  for (auto i = 0; i < a.size(); i++)
    for (auto j = 0; j < b.size(); j++)
      r[i] += a[i] * m[i + j];  // swap loop order

  // print results
  std::cout << r << std::endl;
}
