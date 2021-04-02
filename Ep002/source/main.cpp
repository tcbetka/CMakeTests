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
    const int WIDTH = 800;
    const int HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);
    //bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            bitmap.setPixel(x, y, 255, 255, 255);
        }
    }

    bitmap.write(fileName);

    cout << "Finished" << endl;
    return 0;
}