#include <iostream>
using namespace std;
int main()
{
    const int max = 1000;
    int count = 1;
    bool arr[max];

    for(int i = 0; i < max; ++i)
        arr[i] = true;

    for(int i = 2; i < max; i++)
    {
        //mark all multiples
        for(int j = 2; (j*i) < max-1; ++j) arr[i*j] = false;
    }

    for (int i = 2; i < max; ++i)
        if (arr[i])
            cout << i << " ";
}
