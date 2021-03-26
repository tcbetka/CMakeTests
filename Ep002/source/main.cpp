#include <iostream>
#include <concepts>

using std::cout;
using std::endl;

template <typename T>
requires std::integral<T>
T add(T a, T b) 
{
    return a + b;
}

int main() 
{
    cout << "Hello from C++20 with CMake on Linux" << endl;
    cout << "7 + 5 = " << add(7, 5) << endl; 


    return 0;
}