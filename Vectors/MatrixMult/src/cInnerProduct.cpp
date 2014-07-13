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

double genRand(void)
{
  return rand() / static_cast<double>(RAND_MAX) * 1.0;
}

int main(int argc, char* argv[])
{
  srand(1);
  //srand(std::time(0)); // not sure if J version always generates a new seed so leaving this out for now.
  long elems = std::atol(argv[1]); // command line param
  std::vector<double> m; // (elems * elems); // actually this is a vector of length (N*N)
  std::vector<double> a;
  std::vector<double> r(elems, 0); // r(elems, 0); // to store the result

  for (auto i = 0; i < elems; i++) // generate random vector
    a.push_back(genRand());

  for (auto i = 0; i < elems * elems; i++) // generate random matrix
    m.push_back(genRand());

  for (auto i = 0; i < a.size(); i++) // perform dot product
    for (auto j = 0; j < m.size(); j++)
      r[i] += genRand() * genRand();
      //r[i] += a[i] * m[j];

  std::cout << r << std::endl; // print results
}
