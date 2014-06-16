#include <iostream>
#include <vector>
#include <string>

void plain(void)
{
	for (int n = 1; n <= 100; n++) {

		if ((n % 3 == 0) && (n % 5 == 0))
			std::cout << "FizzBuzz" << std::endl;
		else if (n % 3 == 0)
			std::cout << "Fizz" << std::endl;
		else if (n % 5 == 0)
			std::cout << "Buzz" << std::endl;
		else
			std::cout << n << std::endl;
	}
}

void both(void)
{
	for (int n = 1; n <= 100; n++) {

		std::cout << n << " ";
		if (n % 3 == 0)
			std::cout << "Fizz";
		if (n % 5 == 0)
			std::cout << "Buzz";
		std::cout << std::endl;
	}

}

void stringythingy(void)
{
	std::string msg;

	for (int n = 1; n <= 100; n++) {

		msg.clear();
		if (n % 3 == 0)
			msg += "Fizz";
		if (n % 5 == 0)
			msg += "Buzz";

		if (msg.empty())
			std::cout << n << std::endl;
		else
			std::cout << msg << std::endl;
	}
}

class lookup {
	public:
		lookup()
			: data(100)
		{
			for (int n = 1; n <= 100; n++) {

				if ((n % 3 == 0) && (n % 5 == 0))
					data[n-1] = "FizzBuzz";
				else if (n % 3 == 0)
					data[n-1] = "Fizz";
				else if (n % 5 == 0)
					data[n-1] = "Buzz";
				else
					data[n-1] = std::to_string(n);
			}
		}

		inline const std::string& get(size_t n) const
		{
			if ((n < 1) || (n > 100))
				throw std::invalid_argument("Error: the given input is too small or big!");
			return data[n - 1];
		}

		inline void printAll(void)
		{
			for (auto& x : data) {
				std::cout << x << std::endl;
			}
		}

	private:
		std::vector<std::string> data;
};

int main()
{
//	plain();
//	stringythingy();
//	both();

	lookup l;
	l.printAll();

	return 0;
}

