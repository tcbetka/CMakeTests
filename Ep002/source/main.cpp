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
    
    for (int i = 0; i < myBuffer.size(); i++) {
        cout << myBuffer.get(i) << endl;
    }
    cout << endl;

    myBuffer.add(60);
    myBuffer.add(70);

    for (ring<int>::iterator it = myBuffer.begin(); it != myBuffer.end(); ++it) {
        cout << *it << endl;
    }
    cout << endl;

    for (auto v : myBuffer) {
        cout << v << endl;
    }

    return 0;
}