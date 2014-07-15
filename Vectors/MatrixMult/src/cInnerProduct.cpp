#include <vector>
#include <fstream>
#include <random>
#include <iostream>

std::ostream& operator<< (std::ostream& os, const std::vector<double>& v)
{
  // pretty-print a vector of doubles using operator<<
  for (auto& i : v)
    i == *v.begin() ? os << i : os << " " << i;
  return os;
}

int main(int argc, char* argv[])
{
  // file i/o
  std::ofstream result;
  result.open("output/coutput.txt", std::ios::out);

  // randoms
  std::mt19937 mt(1729);
  std::uniform_real_distribution<double> dist(0,1);
  // for (int i = 0; i < 16; i++) // testing
  //   std::cout << dist(mt) << " ";
  // std::cout << std::endl;

  long elems = std::atol(argv[1]); // command line param
  std::vector<double> m(elems * elems); // (elems * elems); // actually this is a vector of length (N*N)
  std::vector<double> a(elems);
  std::vector<double> r(elems, 0); // to store the result

  for (auto i = 0; i < elems; i++) // generate random vector
  {
    a[i] = dist(mt);
  }

  for (auto i = 0; i < elems * elems; i++) // generate random matrix
  {
    m[i] = dist(mt);
  }

  for (auto i = 0; i < m.size(); i++)
  {
    auto idx = i / a.size();
    r[idx] += a[idx] * m[i];
  }

  result << r << std::endl; // print results
  result.close();
}
