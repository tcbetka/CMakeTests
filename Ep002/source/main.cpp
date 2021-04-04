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

    double min{999999};
    double max{-999999};

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double xFractal = (x - WIDTH/2) * (2.0/WIDTH);
            double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT);

            if (yFractal < min) {
                min = yFractal;
            }
            if (yFractal > max ) {
               max = yFractal;
            }
         }
    }

    cout << min << ", " << max << endl;

    bitmap.write(fileName);

    cout << "Finished" << endl;
    return 0;
}