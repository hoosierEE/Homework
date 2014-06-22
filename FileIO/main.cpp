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
//     filen/*}}}*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

int main(){
  std::ifstream raw;
  std::ofstream results;
  raw.open("raw/test1.csv", std::ios::in);
  results.open("processed/test1processed.txt", std::ios::out);

  std::string line;

  while(!getline(raw,line).eof()){
    std::cout << line << std::endl;
  }

  raw.close();
  results.close();
}
