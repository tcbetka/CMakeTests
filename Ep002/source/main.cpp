#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// Functors can be either classes or structs, and we can implement an inheritance hierarchy
//  just like with other C++ constructs
struct Test
{
    // Make this pure virtual
    virtual bool operator()(std::string& test) = 0;
};

// Now MatchTest MUST implement the operator() overload in order to be instantiable
struct MatchTest : public Test 
{
    // This is what makes a functor a functor -- operator() can take a variable
    //  number of arguments, and can return whatever we want 
    bool operator()(std::string& text) {
        return text == "lion";
    }
};

// Test is abstract, but we can still have pointers or references to a Test object
void check(std::string text, Test& test)
{
    if (test(text)) {
        cout << "Text matches!" << endl;
    } else {
        cout << "No match" << endl;
    }
} 

int main()
{
    MatchTest m;
    std::string str = "lions";

    // Now call check() and pass it our string and our functor reference
    check(str, m);

    return 0;
}