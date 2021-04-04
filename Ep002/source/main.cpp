#include <iostream>
using std::cout;
using std::endl;
using std::flush;
using std::ostream;

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;

#include <cstdint>
using std::uint8_t;

#include "Bitmap.h"
#include "Mandlebrot.h"


int main()
{
    std::string fileName = "test.bmp";
    const int WIDTH = 800;
    const int HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    double min{999999};
    double max{-999999};

    unique_ptr<int[]> histogram(new int[Mandlebrot::MAX_ITERATIONS]{0});

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double xFractal = (x - WIDTH/2 - 200) * (2.0/HEIGHT);    // shift to the right a little using "- 200"
            double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT);

            int iterations = Mandlebrot::getIterations(xFractal, yFractal);
            if (iterations != Mandlebrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }
    
            uint8_t color = static_cast<uint8_t>(256 * static_cast<double>(iterations) / Mandlebrot::MAX_ITERATIONS);
            color = color * color * color;
            bitmap.setPixel(x, y, 0, color, 0);

            if (color < min) {
                min = color;
            }
            if (color > max ) {
               max = color;
            }
         }
    }
    cout << endl;
    int count{0};
    for (int i = 0; i < Mandlebrot::MAX_ITERATIONS; i++) {
        cout << histogram[i] << " " << flush;
        count += histogram[i];
    }
    cout << count << "; " << WIDTH * HEIGHT << endl;

    cout << min << ", " << max << endl;

    bitmap.write(fileName);

    cout << "Finished" << endl;
    return 0;
}