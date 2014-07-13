#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

std::ostream& operator<< (std::ostream& os, const std::vector<double>& v)
{ // pretty-print a vector of doubles using operator<<
  for (auto& i : v)
    i == *v.begin() ? os << i : os << " " << i;
  return os;
}

struct randomGenerator
{ // without this struct, it would always output the same random sequence
  double range; // hey, commenting out this and the next line caused it to segfault at 129 instead of 130!
  randomGenerator(double r = 1.0) : range(r) {};
  double operator()() { return rand()/(double)RAND_MAX * range; }
};

std::vector<double> randVec(std::vector<double> x, long elems)
{ // return a random vector
  // x.reserve(elems);
  std::generate_n(std::back_inserter(x), elems, randomGenerator());
  return x;
}

int main(int argc, char* argv[])
{
  srand(std::time(0));
  long elems = std::atol(argv[1]);
  std::vector<double> m(elems * elems); // actually this is a vector of length (N*N)
  std::vector<double> a;
  std::vector<double> b;
  std::vector<double> r(elems, 0); // to store the result

  // put random values in a and b
  a = randVec(a, elems);
<<<<<<< HEAD
  b = randVec(b, elems); // does it segfault here? nope.
  std::vector<double> r(elems, 0); // to store the result
=======
  b = randVec(b, elems);
>>>>>>> eeaceebd336add13cf18d34e8918d7cf4fad0b0e

  // build random matrix from the two random vectors
  for (auto i = 0; i < m.size(); i++)
    for (auto j = 0; j < a.size(); j++)
      m[i] = a[j] * b[j]; // oh yeah, a and b are the same size. Segfault problem solved.

  //// do inner product
  for (auto i = 0; i < a.size(); i++)
    for (auto j = 0; j < b.size(); j++)
      r[i] += a[i] * m[i + j];  // swap loop order?

  // print results
  std::cout << r << std::endl;
}
