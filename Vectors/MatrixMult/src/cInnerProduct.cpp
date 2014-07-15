#include <vector>
#include <fstream>
#include <random>
#include <algorithm>

std::ostream& operator<< (std::ostream& os, const std::vector<double>& v)
{ // pretty-print a vector of doubles using operator<<
  for (auto& i : v)
    i == *v.begin() ? os << i : os << " " << i;
  return os;
}

template<typename Cont = std::vector<double>>
Cont genRand(std::size_t n)
{ // random vector generator
  Cont results;
  results.reserve(n);
  std::mt19937 mt(1729);
  std::uniform_real_distribution<> dist(0,1);
  auto random = [&]() { return dist(mt); };
  std::generate_n(std::back_inserter(results), n, random);
  return results;
}

int main(int argc, char* argv[])
{ // file i/o
  std::ofstream result;
  result.open("output/coutput.txt", std::ios::out);
  long elems = std::atol(argv[1]); // command line param
  auto a = genRand(elems); // random vector
  std::vector<std::vector<double>> m; // random matrix
  for (auto i = 0; i < elems; i++) {
    m.emplace_back(genRand(elems));
  }
  std::vector<double> r; // to store the result
  r.reserve(elems);
  for (auto it = m.begin(); it != m.end(); ++it) { // using STL algorithm
    auto v = std::inner_product(std::begin(a), std::end(a), std::begin(*it), 0.0);
    r.push_back(v);
  }
  result << r << std::endl; // print results
  // result.close(); // should close itself right?
}
