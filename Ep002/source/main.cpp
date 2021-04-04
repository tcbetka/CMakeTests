#include <iostream>
using std::cout;
using std::endl;

#include "FractalCreator.h"
#include "Zoom.h"

static const std::string fileName = "test.bmp";
static constexpr int WIDTH = 800;
static constexpr int HEIGHT = 600;

int main()
{
    FractalCreator fractalCreator(WIDTH, HEIGHT);
    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run(fileName);

    cout << "Finished" << endl;

    return 0;
}