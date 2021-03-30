#include <iostream>
using std::cout;
using std::endl;

#include "Complex.h"

int main()
{
    Complex c1;
    cout << "c1: " << c1 << endl;

    Complex c2(1.0, 2.0);
    cout << "c2: " << c2 << endl;

    Complex c3 = c2;
    cout << "c3: " << c3 << endl;

    Complex c4;
    c4 = c2;
    cout << "c4: " << c4 << endl;

    Complex c5 = c4 + c2;
    cout << "c5: " << c5 << endl;

    Complex c6 = c2 - c5;
    cout << "c6: " << c6 << endl;

    Complex c7 = c5 + c2 + c3;
    cout << "c7: " << c7 << endl;

    // For these operator+ use-cases, we must use friend functions, as the + operator
    //  will be taking two operands, both of which are not objects of type Complex
    Complex c8 = c7 + 10.0;
    cout << "c8: " << c8 << endl;

    Complex c9 = 10.0 + c7;
    cout << "c7: " << c7 << endl;

    Complex c10 = 10.0 + c2 + c7 - c8 + 11.0;
    cout << "c10: " << c10 << endl;

    if (c2 == c1) {
        cout << "c2 and c1 are equal" << endl;
    } else {
        cout << "c2 and c1 are not equal" << endl;
    }

    if (c2 != c1) {
        cout << "c2 and c1 are not equal" << endl;
    } else {
        cout << "c2 and c1 are equal" << endl;
    }

    return 0;
}