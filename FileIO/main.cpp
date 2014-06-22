#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main(){
  std::ifstream raw;
  std::ofstream results;
  raw.open("raw/test1.csv", std::ios::in);
  results.open("processed/test1processed.txt", std::ios::out);

  //std::cout << type

  raw.close();
  results.close();
}
