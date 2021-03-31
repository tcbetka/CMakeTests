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
    int mPos;
    T* mBuffer;

public:
    // forward-declaration of iterator, which we'll define below
    class iterator;

    ring(int size) : mSize(size), mPos(0) {
        mBuffer = new T[mSize]{0};
    }

    ~ring() { delete [] mBuffer; }

    void add(T value) {

        // Check to see if the buffer is full
        if (mPos == mSize) {
            mBuffer[0] = value;
            mPos = 0;
        }

        // Otherwise just insert it at the end of the array
        mBuffer[mPos] = value;

        mPos++;
    }

    int size() const {
        return mSize;
    }

    T& get(int pos) {
        return mBuffer[pos];
    }

    // Make our class iterable using a range-based for loop. To do this we 
    //  need begin() and end() methods 
    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(mSize, *this);
    }
};

template <typename T>
class ring<T>::iterator
{
private:
    int mPos;
    ring& mRing;

public:
    iterator(int pos, ring& r) : mPos(pos), mRing(r) {}

    // pre-fix version
    iterator& operator++() {
        mPos++;
        return *this;
    }

    // post-fix version
    iterator& operator++(int) {
        mPos++;
        return *this;
    }

    T& operator*() {
        return mRing.get(mPos);
    }

    bool operator!=(const iterator& other) const {
        return mPos != other.mPos;
    }

};


#endif // RING_H