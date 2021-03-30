#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

bool match(std::string test)
{
    // Check to see if the string size is 3 chars
    return test.size() == 3;
}

int countStrings(vector<std::string>& texts, bool (*myMatchFunc)(std::string test)) 
{
    int count = 0;
    for (vector<std::string>::iterator it = texts.begin(); it != texts.end(); it++) {
        if (myMatchFunc(*it)) {
            count++;
        }
    }

    return count;
}

int main()
{
    vector<std::string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");
    texts.push_back("five");
    texts.push_back("size");
    texts.push_back("seven");

    // Now we can search the vector and find the number of strings with three chars
    int number = std::count_if(texts.begin(), texts.end(), match);
    cout << "Number: " << number << endl; 

    // Use our version 
    cout << "Count of strings: " << countStrings(texts, match) << endl;

    return 0;
}