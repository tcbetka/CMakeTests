#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

class Test
{
public:
    Test() { cout << "created" << endl; }
    void greet() { cout << "hello" << endl; }
    ~Test() { cout << "destroyed" << endl; }
};

class Temp
{
public:
    // We can have an instance variable of type unique_ptr, we simply
    //  need to initialize it in the ctor like we do with any other
    //  variable
    unique_ptr<Test[]> pTest;

    // Or we can use an initialization list since C++11
    unique_ptr<Test[]> pTest2{new Test[2]};

public:
    Temp() : pTest(new Test[2]) {}
};

int main()
{
    // Use { } to establish a scope    
    {
        /*
        // Create a unique_ptr as the only thing pointing at an object. This will deallocate
        //  memory automatically when the unique_ptr goes out of scope. Note: This is very
        //  similar to the pre-c++11 "auto_ptr" that has now been deprecated. 
        unique_ptr<Test> pTest(new Test);

        // Now use the unique_ptr just like a regular pointer
        pTest->greet();
        */
    }
    cout << endl << endl;

    {
        /*
        // We can also use a unique_ptr on arrays too
        unique_ptr<Test[]> pTest(new Test[2]);

        // Now we have two Test objects to call methods on, and both will be destroyed when the 
        //  unique_ptr goes out of scope. 
        pTest[0].greet();
        pTest[1].greet(); 
        */
    }

    // Test our Temp class objects
    {
        Temp temp1;
        //temp1.pTest[0]->greet();
        temp1.pTest[0].greet();
        temp1.pTest[1].greet();
        cout << endl;
        temp1.pTest2[0].greet();
        temp1.pTest2[1].greet();
    }


    cout << "\nFinished" << endl;
    return 0;
}