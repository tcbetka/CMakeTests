#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <functional>
using std::function;

#include <algorithm>
using std::count_if;

bool check(const std::string &test)
{
    return test.size() == 3;
}

class Check
{
public:
    bool operator()(const std::string &test)
    {
        return test.size() == 5;
    }
};

void run(function<bool(std::string)> check) 
{
    std::string test = "dog";
    cout << "check(test): " << check(test) << endl;
}

int main()
{
    vector<std::string> vec{"one", "two", "three"};

    auto lambda = [](std::string str) { return str.size() == 3; };

    // Count the number of strings in the vector that have three characters. Our third argument is
    //  a lambda that simply takes in each string from the vector, and returns whether or not it has 3 chars
    int count = count_if(vec.begin(), vec.end(), lambda);
    cout << "Count1 = " << count << endl;

    // Recall that we can do the same thing using an ordinary function pointer
    count = count_if(vec.begin(), vec.end(), check);
    cout << "Count2 = " << count << endl;

    // We can also do the same thing using a functor as our final argument
    Check c1;
    count = count_if(vec.begin(), vec.end(), c1);
    cout << "Count2 = " << count << endl;

    // We can use our functional object as well
    run(lambda);

    return 0;
}