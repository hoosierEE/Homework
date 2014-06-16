

#ifndef __CURIOUS_H__
#define __CURIOUS_H__

#include <iostream>

struct PrintYes {
	std::ostream& print(std::ostream& os)
	{
		os << "Yes" << std::endl;
		return os;
	}
};

struct PrintNo {
	std::ostream& print(std::ostream& os)
	{
		os << "No" << std::endl;
		return os;
	}
};

// general form
template <typename T>
constexpr bool isPrintType() {
  return false;
}
// specialization
template <>
constexpr bool isPrintType<PrintYes>() {
  return true;
}
// specialization
template <>
constexpr bool isPrintType<PrintNo>() {
  return true;
}

// error message if you try to give the wrong type
template <typename F>
struct PrintSomething : public F {
  static_assert (isPrintType<F>(), "must be derived from PrintType");
};




#endif // __CURIOUS_H__
