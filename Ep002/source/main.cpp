#include <iostream>
using std::cout;
using std::endl;

void test() 
{
    cout << "Hello" << endl;
}

void test2(int a)
{
    cout << "a: " << a << endl;
}

int main()
{
    // Declare a function pointer, and point it to the test function
    void (*fPtr)();
    fPtr = test;

    // Now we can call the test() function via the function pointer
    fPtr();

    // Or we can also dereference the function pointer and use that to call the function
    (*fPtr)();

    // We can have function pointers to functions that take parameters as well 
    void (*fPtr2)(int) = test2;
    fPtr2(10);

    return 0;
}