#include <iostream>
#include <vector>

template <typename T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& v)
{ // pretty-print a vector using operator<<
  for (auto& i : v)
    i == *v.begin() ? os << i : os << ", " << i;
  return os;
}

int main(int argc, char* argv[]) {

  // // fail early, fail often
  // if (argc <= 4) {
  //   std::cerr << "must call with at least 4 space-separated integers" << std::endl;
  //   return 1;
  // }

  // hard-coded vector
  std::vector<int> vec = { 0, 1, 2, 3 };

  // hard-coded matrix (2 dimensional array)
  std::vector<std::vector<int>> mx =
  { { 0, 1, 2, 3 }
  , { 1, 2, 3, 4 }
  , { 2, 3, 4, 5 }
  , { 3, 4, 5, 6 }
  };

  // accumulate column values
  std::vector<int> acc = { 0, 0, 0, 0 };

  // multiply vec times columns of mx, store results in acc
  for (int i = 0; i < vec.size(); i++)        // column
    for (int j = 0; j < vec.size(); j++)      // row
      acc[i] += vec[j] * mx[i][j];            // multiply-accumulate

  std::cout << acc << std::endl;
}
