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
private:
    static constexpr int SIZE = 100;
    int *mBuffer;

public:
    Test()
    {
        cout << "Constructor" << endl;
        mBuffer = new int[SIZE]{0};
    }

    Test(int i)
    {
        cout << "Parameterized constructor" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            mBuffer[i] = 7 * i;
        }
    }

    Test(const Test &other)
    {
        cout << "Copy constructor" << endl;

        mBuffer = new int[SIZE];
        memcpy(mBuffer, other.mBuffer, SIZE * sizeof(int));
    }

    Test &operator=(const Test &other)
    {
        cout << "Assignment" << endl;

        mBuffer = new int[SIZE];
        memcpy(mBuffer, other.mBuffer, SIZE * sizeof(int));

        return *this;
    }

    ~Test()
    {
        cout << "Destructor" << endl;
        delete[] mBuffer;
    }

    friend ostream& operator<<(ostream& out, const Test& other);
};

ostream& operator<<(ostream& out, const Test& other)
{
    out << "Hello from test";
    return out;
}

Test getTest()
{
    return Test();
}

int main()
{
    Test test1 = getTest();
    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    // lvalue reference, as we can take the address of test1
    Test* pTest1 = &test1;
    Test& rTest1 = test1;

    // This won't work though, as getTest() is an rvalue 
    //Test& test2 = getTest();

    // But you CAN do it, if test2 is marked const--because it forces the lifetime of the rvalue
    //  gets pushed out to that of the const reference. This is no different than a copy ctor
    //  taking a const Test& parameter to an rvalue, which has the lifetime of the copy ctor.
    const Test& test2 = getTest();

    return 0;
}