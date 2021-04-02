#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

#include <cstring>
using std::memcpy;

class Test
{

};

// The argument to call could be an rvalue or an lvalue, based upon the reference-collapsing
//  rules as seen in main
template <typename T>
void call(T&& arg) {
    // Since 'arg' is an lvalue in the context of this function (ie; we can take its address),
    //  we need to cast arg to type T in order to correctly capture whether or not it was an
    //  rvalue or an lvalue that gets passed in as an argument. This is "perfect forwarding"
    check(static_cast<T>(arg));

    // We can use std::forward to make this process more explicit
    check(std::forward<T>(arg));
}

void check(Test& test) {
    cout << "lvalue" << endl;
}

void check(Test&& test) {
    cout << "rvalue" << endl;
}

int main()
{
    // rvalue reference is OK
    auto&& t1 = Test();

    // Can't point an rvalue reference at a non-const lvalue
    Test test;
    //Test&& t2 = test; // ERROR

    // However when we use 'auto,' the reference-collapsing rules allow this
    auto&& t3 = test;

    call(Test());
    call(test);

    return 0;
}