#ifndef RING_H
#define RING_H

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class ring
{
private: 
    int mSize;
    int mElementCount;
    T* mBuffer;

public:
    // forward-declaration of iterator, which we'll define below
    class iterator;

    ring(int size) : mSize(size), mElementCount(0) {
        mBuffer = new T[mSize]{0};
    }

    ~ring() { delete [] mBuffer; }

    void add(T value) {

        // Check to see if the buffer is full
        if (mElementCount == mSize) {
            mBuffer[0] = value;
            mElementCount = 0;
        }

        // Otherwise just insert it at the end of the array
        mBuffer[mElementCount] = value;

        mElementCount++;
    }

    void print() const {
        for (int i = 0; i < mSize; i++) {
            cout << mBuffer[i] << endl;
        }
    }
};

template <typename T>
class ring<T>::iterator
{
private:

public:
    void print() const { cout << "Hello from iterator" << endl; }
};


#endif // RING_H