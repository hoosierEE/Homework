

#ifndef __TAGGING_H_
#define __TAGGING_H_

#include <iostream>

struct SayHi {};

struct SayBye {};

template <typename F>
class SaySomething {

	public:

		std::ostream& print(std::ostream& os)
		{
			return print(F(), os);
		}

	private:
		std::ostream& print(SayHi, std::ostream& os)
		{
			os << "Hi" << std::endl;
			return os;
		}

		std::ostream& print(SayBye, std::ostream& os)
		{
			os << "Bye" << std::endl;
			return os;
		}

};


#endif // __TAGGING_H_
