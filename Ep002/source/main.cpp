#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;

class Test
{
public:
    Test() { cout << "created" << endl; }
    void greet() { cout << "hello" << endl; }
    ~Test() { cout << "destroyed" << endl; }
};



int main()
{
    // Shared pointers are similar to unique pointers, except they don't delete the memory 
    //  associated with the object until ALL objects have gone out of scope. 
    //shared_ptr<Test> pTest(new Test());

    // Here's a better syntax, which doesn't use 'new' (which can throw an exception)
    shared_ptr<Test> pTest = make_shared<Test>();
    cout << "going into the blocks..." << endl; 
    {
        // Create a second pointer to the object
        shared_ptr<Test> pTest2 = pTest;
    }
    cout << "out of the blocks..." << endl;

    cout << "Finished" << endl; 
    return 0;
}