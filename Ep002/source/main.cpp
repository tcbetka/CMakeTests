#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

#include <functional>
using std::bind;


int add(int a, int b, int c) {
    cout << a << " + " << b << " + " << c << " = "; 
    return a + b + c;
}

int main()
{
    cout << add(1, 2, 3) << endl;

    // std::bind allows you to declare aliases to functions 
    auto calc1 = bind(add, 3, 4, 5);
    cout << calc1() << endl;

    // now we can also add placeholders and then supply arguments
    auto calc2 = bind(add, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    cout << calc2(10, 20, 30) << endl;


    return 0;
}