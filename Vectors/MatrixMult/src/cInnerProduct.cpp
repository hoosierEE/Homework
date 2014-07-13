#include <vector>
#include <fstream>

const std::string outputName = "output/coutput.txt"; // the name of the file this program makes

std::ostream& operator<< (std::ostream& os, const std::vector<double>& v)
{ // pretty-print a vector of doubles using operator<<
  for (auto& i : v)
    i == *v.begin() ? os << i : os << " " << i;
  return os;
}

double genRand(void)
{
  return rand() / static_cast<double>(RAND_MAX);
}

int main(int argc, char* argv[])
{
  // file i/o
  std::ofstream result;
  result.open(outputName, std::ios::out);

  srand(1);
  //srand(std::time(0)); // not sure if J version always generates a new seed so leaving this out for now.
  long elems = std::atol(argv[1]); // command line param
  std::vector<double> m(elems * elems); // (elems * elems); // actually this is a vector of length (N*N)
  std::vector<double> a(elems);
  std::vector<double> r(elems, 0); // r(elems, 0); // to store the result

  for (auto i = 0; i < elems; i++) // generate random vector
    //a[i] = genRand();
    a.push_back(genRand());

  for (auto i = 0; i < elems * elems; i++) // generate random matrix
    //m[i] = genRand();
    m.push_back(genRand());

  for (auto i = 0; i < m.size(); i++) { // about 12% faster than commented-out loop below.
    static auto idx = i / a.size();
    r[idx] += a[idx] * m[i];
  }

  result << r << std::endl; // print results
  result.close();
}
