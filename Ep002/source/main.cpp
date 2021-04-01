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
    int* mBuffer{nullptr};

public:
    Test()
    {
        //cout << "Constructor" << endl;
        mBuffer = new int[SIZE]{0};
    }

    Test(int i)
    {
        //cout << "Parameterized constructor" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            mBuffer[i] = 7 * i;
        }
    }

    Test(const Test &other)
    {
        //cout << "Copy constructor" << endl;

        mBuffer = new int[SIZE];
        memcpy(mBuffer, other.mBuffer, SIZE * sizeof(int));
    }

    // Move constructor -- allows us to simply steal resources from the object passed in
    Test(Test&& other) {
        cout << "Move constructor" << endl;

        // Check first for self-assignment
        if (this->mBuffer != other.mBuffer) {
            mBuffer = other.mBuffer;
        }

        // Reset the object stolen from, then delete it
        other.mBuffer = nullptr;
        delete [] other.mBuffer;
    }

    // Move assignment operator 
    Test& operator=(Test&& other) {
        cout << "Move assignment" << endl;

        // Check first for self-assignment 
        if (this->mBuffer != other.mBuffer) {
            // Make sure our current object doesn't have any resources
            delete [] mBuffer;

            // Now assign from the other object, and then set it to null to avoid repeated deletions
            mBuffer = other.mBuffer;
            other.mBuffer = nullptr;
        }

        return *this;
    }

    Test &operator=(const Test &other)
    {
        //cout << "Assignment" << endl;

        mBuffer = new int[SIZE];
        memcpy(mBuffer, other.mBuffer, SIZE * sizeof(int));

        return *this;
    }

    ~Test()
    {
        cout << "Destructor" << endl;
        if (mBuffer) {
            delete[] mBuffer;
        }
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
    vector<Test> vec;

    // This is inefficient unless copy elision is turned on in the compiler settings, or we
    //  use move semantics
    vec.push_back(Test());

    Test test;
    test = getTest();


    return 0;
}