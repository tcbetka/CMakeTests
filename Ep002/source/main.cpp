#include <iostream>
using std::cout;
using std::endl;

#include "FractalCreator.h"

static const std::string fileName = "test.bmp";
static constexpr int WIDTH = 800;
static constexpr int HEIGHT = 600;

int main()
{
    FractalCreator fractalCreator(WIDTH, HEIGHT);
    fractalCreator.addZoom(Zoom(295, HEIGHT - 202, 0.1));
    fractalCreator.addZoom(Zoom(312, HEIGHT - 304, 0.1));
    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap(fileName);

    cout << "Finished" << endl;
    return 0;
}