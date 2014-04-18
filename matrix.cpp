#include <iostream>
#include <string>
#include <sstream>

std::string mystr = "";

int row, col;

int main() {

  std::cout << "For your m by n matrix, "
     "enter first the number of rows (m), then a space, "
     "then the number of columns (n): " << std::endl;

  std::cin >> row >> col;

  std::cout << "I guess this is going to be an " << row << " by " << col << " matrix." << std::endl;
  
  std::cout << "Next, enter a vector by which your matrix will be multiplied: " << std::endl;

  // std::cout << "Input a vector, delimited by spaces (e.g. 1 2 3): " << std::endl;

  
  getline (std::cin, mystr);
  std::istringstream ss(mystr);

//  std::cout << "you said: " << std::endl;

  for(std::string word; ss >> word;) {
    std::cout << word << std::endl;
  }



  return 0;
}
