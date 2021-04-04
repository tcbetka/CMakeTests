#include <iostream>
using std::cout;
using std::endl;

#include "FractalCreator.h"
#include "RGB.h"


static const std::string fileName = "test.bmp";
static constexpr int WIDTH = 800;
static constexpr int HEIGHT = 600;

int main()
{
    FractalCreator fractalCreator(WIDTH, HEIGHT);
    fractalCreator.run(fileName);

    cout << "Finished" << endl;

    return 0;
}