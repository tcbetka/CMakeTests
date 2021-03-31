#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;


int main()
{
    const char* texts[] = { "one", "two", "three" };

    // Enhanced for loop 
    for (auto text: texts) {
        cout << text << endl;
    }

    vector<int> numbers{ 5, 7, 9, 11 };
    for (auto n : numbers) {
        cout << n << endl;
    }

    std::string hello = "Hello World";
    for (auto c : hello) {
        cout << c << endl;
    }

    return 0;
}