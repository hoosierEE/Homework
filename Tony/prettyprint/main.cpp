#include <iostream>
#include <vector>


// unroll first
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
//	typename std::vector<T>::const_iterator it = v.begin();
	auto it = v.begin();
	os << *it++;
	while (it != v.end()) {
		os << ',' << *it++;
	}
	return os;
}

//// unroll first
//// less safe; array-style indexing may go out of bounds
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
//{
//	os << v[0];
//	for (size_t idx = 1; idx < v.size(); idx++) {
//		os << ',' << v[idx];
//	}
//	return os;
//}
//
//// unroll last
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
//{
//	auto it = v.begin();
//	auto et = v.end() - 1;
//	while (it != et) {
//		os << *it++ << ',';
//	}
//	os << *it;
//	return os;
//}

int main()
{
	std::vector<float> floatArray    = {1.1, 10, 82, 4, 5};
	std::vector<int>   integralArray = {1, 10, 82, 4, 5};
	std::vector<char>  charArray     = {'h', 'e', 'l', 'l', 'o'};

	std::cout << floatArray << std::endl;
	std::cout << integralArray << std::endl;
	std::cout << charArray << std::endl;

	return 0;
}
