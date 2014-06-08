#include <iostream>
#include <string>

using namespace std;

template <typename T>
T modulator (T numerator, T divisor) {
  return !(numerator % divisor);
}

template <int n> struct
fb {
  static const int value = fb<n >> 1>::value;
};

//template <int T> class
//modu {
//  modu() { cout << T << endl; };
//  ~modu() {};
//};
//template<0> class
//modu {
//  modu() { cout << "special" << endl; };
//  ~modu() {};
//}

int main() {

  int startNumber = 100;

  while (startNumber--){
    if (modulator(startNumber, 15))
      cout << startNumber << " fizzbuzz" << endl;
    else if (modulator(startNumber, 5))
      cout << startNumber << " buzz" << endl;
    else if (modulator(startNumber, 3))
      cout << startNumber << " fizz" << endl;
    else cout << startNumber << endl;
  }

}
