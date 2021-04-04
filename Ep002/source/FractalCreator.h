#ifndef FRACTAL_CREATOR_H
#define FRACTAL_CREATOR_H

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <cstdint>
using std::uint8_t;

#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "Mandlebrot.h"
#include "RGB.h"

class FractalCreator
{
public:
    FractalCreator(int width, int height);
    void run(string name);
    void addZoom(const Zoom &zoom);

private:
    void calculateIteration();
    void calculateTotalIterations();
    void drawFractal();
    void writeBitmap(string name);

private:
    int mWidth{0};
    int mHeight{0};
    unique_ptr<int[]> mHistogram;
    unique_ptr<int[]> mFractal;
    Bitmap mBitmap;
    ZoomList mZoomList;
    int mTotalIterations{0};
};

#endif // FRACTAL_CREATOR_h