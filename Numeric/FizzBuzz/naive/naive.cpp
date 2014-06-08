#include <iostream>

using namespace std;

int main() {
  int startNumber = 100;
  while (startNumber--) {
    if (!(startNumber % 15))
      cout << startNumber << " fizzbuzz" << endl;
    else if (!(startNumber % 5))
      cout << startNumber << " buzz" << endl;
    else if (!(startNumber % 3))
      cout << startNumber << " fizz" << endl;
    else
      cout << startNumber << endl;
  }
}
