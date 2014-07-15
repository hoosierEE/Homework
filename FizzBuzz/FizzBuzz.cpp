#include <iostream>

bool fizzBuzzer(int i) {
  bool quiet = true;
  if (i % 3 == 0) {
    std::cout << "Fizz";
    quiet = false;
  }
  if (i % 5 == 0) {
    std::cout << "Buzz";
    quiet = false;
  }
  return quiet;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "call with a positive integer" << std::endl;
    return 1;
  }
  int startNumber = std::atoi(argv[1]);

  for (auto i = 0; i < startNumber; i++) {
    if (fizzBuzzer(i)) {
      std::cout << i << std::endl;
    }
    else {
      std::cout << std::endl;
    }
  }
}
