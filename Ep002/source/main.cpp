#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <typeinfo>

// Here's an example of the use of decltype: It negates the need to know
//  the type of the returned value, and can also evaluate expressions.
template <class S, class T>
auto test(S value1, T value2) -> decltype(value1 + value2)
{
    return value1 + " " + value2;
}

int main()
{
    int intNum;
    double dblNum;
    float fltNum;
    char chrNum;
    std::string str;

    cout << typeid(intNum).name() << endl;  // output: i
    cout << typeid(dblNum).name() << endl;  // output: d
    cout << typeid(fltNum).name() << endl;  // output: f
    cout << typeid(chrNum).name() << endl;  // output: c
    cout << typeid(str).name() << endl;     // ouput: a mangled name

    // decltype is a C++11 construct that allows us to declare variables based upon that 
    //  of an existing type. This is useful when we need to create a variable but we don't 
    //  actually know the type--but we can get it from the type of other variables in our program.

    // For example: This will create number as an integer
    decltype(intNum) number;
    cout << typeid(number).name() << endl; // output: i

    auto text1 = "Hello";                   // const char*
    auto text2 = std::string("Hello");      // std::string
    cout << typeid(text1).name() << endl;   // output: 
    cout << typeid(text2).name() << endl;   // output: 

    auto test_value = test(std::string("hello"), std::string("world"));
    cout << test_value << endl;
    cout << typeid(test_value).name() << endl;

    return 0;
}