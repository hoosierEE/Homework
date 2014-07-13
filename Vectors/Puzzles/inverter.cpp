#include <iostream>
#include <math.h>

// an interview question:
// "design a function such that f(f(n)) == -n, where n is a 32 bit signed int,
// and which does not use complex numbers"

int minusItself(int n)
{ // are globals or external state considered "complex numbers"?
  // a very philosophical question.
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
  if (n == int(n)) // first time called
    return n + 0.1;
  else
    return int(-n + 0.1);
}

int main()
{
  for (int i = -3; i < 4; i++)
    std::cout << "minusItself(minusItself(" << i << "): " << minusItself(minusItself(i)) << std::endl;
  for (int i = -3; i < 4; i++)
    std::cout << "changesItself(changesItself(" << i << "): " << changesItself(changesItself(i)) << std::endl;
}
