// typetest.cpp
//
// how big are the types?
// do we have support for these type names?
//
// compile with:
// g++ -std=c++0x test.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<string> names =
{ "sizeof(int64_t)  = "
, "sizeof(uint64_t) = "
, "sizeof(int32_t)  = "
, "sizeof(uint32_t) = "
, "sizeof(int16_t)  = "
, "sizeof(uint16_t) = "
, "sizeof(int8_t)   = "
, "sizeof(uint8_t)  = "
};

vector<int> sizes =
{ sizeof(int64_t)
, sizeof(uint64_t)
, sizeof(int32_t)
, sizeof(uint32_t)
, sizeof(int16_t)
, sizeof(uint16_t)
, sizeof(int8_t)
, sizeof(uint8_t)
};


int main()
{
  for (int i = 0; i < names.size(); i++)
    cout << names[i] << sizes[i] << endl;
}
