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

#include <cmath>
using std::pow;

#include <utility>
using std::pair;

#include "Bitmap.h"
#include "Mandlebrot.h"
#include "Zoom.h"
#include "ZoomList.h"


int main()
{
    std::string fileName = "test.bmp";
    const int WIDTH = 800;
    const int HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    double min{999999};
    double max{-999999};

    unique_ptr<int[]> histogram(new int[Mandlebrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

    ZoomList zoomList(WIDTH, HEIGHT);
    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pair<double, double> fractalCoords = zoomList.doZoom(x, y);
            int iterations = Mandlebrot::getIterations(fractalCoords.first, fractalCoords.second);

            fractal[y*WIDTH + x] = iterations;

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

    int total{0};
    for (int i = 0; i < Mandlebrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = fractal[y * WIDTH + x];
            if (iterations != Mandlebrot::MAX_ITERATIONS) 
            {
                double hue = 0.0;
                for (int i = 0; i <= iterations; i++) {
                    hue += static_cast<double>(histogram[i]) / total;
                }
                green = pow(255, hue);
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bitmap.write(fileName);

    cout << "Finished" << endl;
    return 0;
}