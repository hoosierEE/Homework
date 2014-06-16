#include <iostream>
#include <string>

using namespace std;

template <typename T> string
fb(T num) {
  string answer = "";
  string stringifiedNum = to_string(num);
  return stringifiedNum;
}

int main() {

  int startNumber = 100;

  do {
    cout << fb(startNumber) << endl;
  } while (--startNumber);
}
