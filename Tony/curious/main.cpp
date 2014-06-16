
#include "curious.h"
#include "tagging.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hey Dude!" << endl;

	PrintSomething<PrintYes>().print(std::cout);
	SaySomething<SayBye>().print(std::cout);

	return 0;
}

