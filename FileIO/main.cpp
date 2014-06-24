// a c++ file to process the results of a data logging run of my oscilloscope.
// the scope saves its run as a bunch of csv files, to use this program, put the
// scope files in a directory "raw" and position this program so it can access raw/[files].
// that is, the top-level structure should look like this:
//
// some-dir/
//   this_program
//   raw/
//     file1
//     file2
//     ...
//     fileN

// includes
#include <fstream>
#include <vector>
#include <sstream>

// constants
const std::string inputNameList = "csvNames";
const std::string outputName = "processed/test1processed.txt";

// functions
std::vector<std::string> csvFileVector(std::string fileName) {
  // get the names of the CSV files from a pre-generated text file
  std::vector<std::string> result;
  std::ifstream f;
  std::string line;
  // open the file and read the lines into a vector of strings
  f.open(fileName, std::ios::in);
  while(!getline(f, line).eof()) {
    result.push_back(line);
  }
  f.close();
  return result;
}

std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

// program
int main() {
  // open a stream for writing
  int n = 0;
  std::ofstream result;
  result.open(outputName, std::ios::out);

  // read the streams
  for(auto& csvFile : csvFileVector(inputNameList)){
    // std::cout << csvFile << std::endl; // prints 'test1.csv test2.csv' etc.
    std::string row;
    std::ifstream f;
    f.open(csvFile, std::ios::in);

    while(!std::getline(f, row).eof()) {
      std::vector<std::string> elms;
      // split the row
      split(row, ',', elms);
      // concat the nth column to the output file
      result << elms[elms.size() - (1 + n)] << std::endl;
    }
    f.close();
  }
  // close the output stream
  result.close();
}
