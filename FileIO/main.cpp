// a c++ file to process the results of a data logging run of my oscilloscope./*{{{*/
// the scope saves its run as a bunch of csv files, to use this program, put the
// scope files in a directory "raw" and position this program so it can access raw/[files].
// that is, the to-level structure should look like this:
//
// some-dir/
//   this_program
//   raw/
//     file1
//     file2
//     ...
//     filen
//

// includes
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
/*}}}*/

std::vector<std::string> csvList(std::string fileName) {
  std::vector<std::string> result;
  std::ifstream f;
  std::string line;
  // open the file and read the lines into a vector of strings
  f.open(fileName, std::ios::in);
  while(!getline(f, line).eof()){
    result.push_back(line);
  }
  f.close();
  return result;
}


int main() {

  // open a stream for writing
  std::ofstream result;
  result.open("processed/test1processed.txt", std::ios::out);

  for(auto& csvFile : csvList("csvNames")){
    for(auto& row : csvFile) {
      std::ifstream raw (csvFile, std::ios::in);
      std::string line;
      while(!getline(raw, line).eof()) {
        std::cout << line << std::endl;
      }
      raw.close();
    }
  }

//  for(auto& filename : csvList("csvNames")){
//    std::ifstream raw;
//    raw.open(filename, std::ios::in);
//    std::cout << filename << std::endl;
//
//    std::string line;
//    while(!getline(raw,line).eof()){
//      std::cout << line << std::endl;
//    }
//    raw.close();
//    std::cout << std::endl;
//    std::cout << std::endl;
//  }
//
  // close the output stream
  result.close();
}
