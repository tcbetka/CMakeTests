#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// Can make a base class uninstantiable by creating at least one pure virtual method
class Animal
{
public: 
    // This is pure virtual, making the entire class "abstract" and therefore uninstantiable
    //  So now any class that wishes to derive from Animal MUST provide an implementation for
    //  the pure virtual function(s) in the Animal class
    virtual void speak() = 0;
    virtual void run() = 0;
};

class Dog : public Animal
{
public:
    // Must implement all pure virtual methods in its base class, or it will itself 
    //  be an abstract class
    virtual void speak() override { cout << "Woof!" << endl; }

    // Because we haven't provided an implementation for the Animal::run() method, 
    //  the Dog class is still abstract, and as such cannot be instantiated
};

class Labrador : public Dog 
{
public:
    virtual void run() override { cout << "Running!" << endl; }
};

int main()
{
    Labrador d;
    d.speak();  // From Dog class
    d.run();    // From Labrador class
    cout << endl;

    // Cannot do this, because Animal class is abstract and this line will 
    //  cause the Animal ctor to run 5 times...which cannot happen as Animal
    //  is an abstract class. 
    //      Animal animals[5];

    // We can however create an array of Animal pointers, however when we loaded
    //  the array we'd need to use concrete (ie; non-virtual) derived class objs
    Animal* animals[5];
    animals[0] = &d;
    animals[0]->speak();
    animals[0]->run();

    return 0;
}