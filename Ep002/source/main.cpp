#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Test 
{
private: 
    // Can use either syntax in c++11
    int one{1};
    int two = 2;

public:
    void run() {
        int three = 3;
        int four = 4;

        // Use the 'this' keyword to capture the instance variables by REF
        auto pLambda = [this, three, four]() {
            one = 111;
            two = -250;
            cout << one << endl;
            cout << two << endl;
            cout << three << endl;
            cout << four << endl;
        };
        pLambda();
    }
};

void test(void (*pFunc)()) 
{
    pFunc();
}

int main()
{
    // Basic syntax of a lambda function -- which can be called using the last () 
    auto func = [](){ cout << "Hello World" << endl; };
    
    // We can pass a lambda just as if it were a function pointer
    //test(func);

    // We can also simply define the function right in-place, in a function argument list
    test( [](){ cout << "Hello World" << endl; } );

    // Our lambda expresion/function can take args 
    auto pGreet = [](std::string name) { cout << "Hello " << name << endl; };
    pGreet("Mike");

    // It can have a return type, using the trailing return type syntax. If the compiler 
    //  can infer the return type then we don't need to include it. 
    auto pDivide = [](double a, double b) -> double {
        if (b != 0.0) {
            return a / b;
        } else  {
            return 0.0;
        }
    };

    // We can have lambdas capture values both by value, and by reference
    int x = 10;
    int y = 5;

    // Capture all local vars by value
    auto pMulti = [=] () {
        cout << "10 * 5 = " << x * y << endl; 
    };
    pMulti();

    // Can capture some by value and some by reference as well (x by ref, y by value)
    auto pMulti2 = [y, &x]() {
        x++;
        cout << x << " * " << y << " = " << x * y << endl;
    };
    pMulti2();

    // Can also capture 'this' with a lambda 
    Test test;
    test.run();

    // Mutable lambda example
    int cats = 5;
    // capture cats by value, so we cannot change it inside the lambda
    [cats] () { cout << "cats: " << cats << endl; }();

    // Using the mutable keyword allows us to change the captured var(s), but only in the lambda.
    //  So it will still be '5' here...
    [cats] () mutable { cats++; cout << "mutable cats: " << cats << endl; }();
    cout << "cats after mutable lambda: " << cats << endl;

    return 0;
}