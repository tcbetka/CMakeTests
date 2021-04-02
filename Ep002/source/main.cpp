#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;

#include "Bitmap.h"


int main()
{
    std::string fileName = "test.bmp";

    Bitmap bitmap(800, 600);
    bitmap.write(fileName);

    cout << "Finished" << endl; 
    return 0;
}