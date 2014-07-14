#include <iostream>

// an interview question:
// "design a function such that f(f(n)) == -n, where n is a 32 bit signed int,
// and which does not use complex numbers"
//
// are globals or external state considered "complex numbers"?
// a philosophical question.

int minusItself(int n)
{
  static bool hasCalledItself = false;
  if (hasCalledItself) {
    hasCalledItself = false;
    return n;
  }
  hasCalledItself = true;
  return -n;
}

double changesItself(double n)
{ // uses doubles instead of ints. again, this is "extra info"
  // and would fit a liberal definition of a complex number.
  return (n == static_cast<int>(n)) ? n + 0.1 : static_cast<int>(-n + 0.1);
}

int main()
{
  for (int i = -1; i < 2; i++)
    std::cout << "minusItself(minusItself(" << i << "): " << minusItself(minusItself(i)) << std::endl;

  std::cout << std::endl;

  for (int i = -1; i < 2; i++)
    std::cout << "changesItself(changesItself(" << i << "): " << changesItself(changesItself(i)) << std::endl;
}

// output:
//
// minusItself(minusItself(-1): 1
// minusItself(minusItself(0): 0
// minusItself(minusItself(1): -1
//
// changesItself(changesItself(-1): 1
// changesItself(changesItself(0): 0
// changesItself(changesItself(1): -1
