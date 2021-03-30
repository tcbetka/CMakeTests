#include <iostream>
using std::cout;
using std::endl;

// Can have class templates
template<typename T, typename U>
class Test
{
private:
    T mObj1;
    U mObj2;

public:
    Test(T obj1, U obj2) : mObj1(obj1), mObj2(obj2) {}

    void print() const {
        cout << "mObj1: " << mObj1 << "\tmObj2: " << mObj2 << endl;
    }
};

// Can also have function templates
template<typename T>
void print(T arg) {
    cout << "arg: " << arg << endl;
}


int main()
{
    Test<int, double> test1(1, 10.001);
    test1.print();

    Test<double, char> test2(3.14159, 'a');
    test2.print();

    Test<std::string, std::string> test3("Hello", "World");
    test3.print();

    // Use our template function, explicitly indicating the template type
    print<int>(1);
    print<double>(3.14);

    // Or...the compiler will even infer the type for us
    print(4.56);
    print("Hello");

    return 0;
}