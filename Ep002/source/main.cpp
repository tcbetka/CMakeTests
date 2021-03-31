#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "ring.h"

int main()
{
    ring<int> myBuffer(5);
    myBuffer.add(10);
    myBuffer.add(20);
    myBuffer.add(30);
    myBuffer.add(40);
    myBuffer.add(50);
    
    myBuffer.print();
    cout << endl;

    myBuffer.add(60);
    myBuffer.add(70);
    myBuffer.print();

    ring<int>::iterator it;
    it.print();

    return 0;
}