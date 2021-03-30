#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <typeinfo>



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



    return 0;
}