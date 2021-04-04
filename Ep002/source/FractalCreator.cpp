#include <utility>
using std::pair;

#include "FractalCreator.h"

FractalCreator::FractalCreator(int width, int height) :
    mWidth(width),
    mHeight(height),
    mHistogram(new int[Mandlebrot::MAX_ITERATIONS]{0}),
    mFractal(new int[mWidth * mHeight]{0}),
    mBitmap(mWidth, mHeight),
    mZoomList(mWidth, mHeight)
{
    addZoom(Zoom(mWidth/2, mHeight/2, 4.0/mWidth));
}

void FractalCreator::run(string name)
{
    addZoom(Zoom(295, mHeight - 202, 0.1));
    addZoom(Zoom(312, mHeight - 304, 0.1));
    calculateIteration();
    calculateTotalIterations();
    drawFractal();
    writeBitmap(name);   
}

void FractalCreator::calculateIteration()
{
    for (int y = 0; y < mHeight; y++) 
    {
        for (int x = 0; x < mWidth; x++) 
        {
            pair<double, double> fractalCoords = mZoomList.doZoom(x, y);
            int iterations = Mandlebrot::getIterations(fractalCoords.first, fractalCoords.second);

            mFractal[y*mWidth + x] = iterations;

            if (iterations != Mandlebrot::MAX_ITERATIONS) {
                mHistogram[iterations]++;
            }
    
            uint8_t color = static_cast<uint8_t>(256 * static_cast<double>(iterations) / Mandlebrot::MAX_ITERATIONS);
            color = color * color * color;
            mBitmap.setPixel(x, y, 0, color, 0);
        }
    }
}

void FractalCreator::calculateTotalIterations()
{
    for (int i = 0; i < Mandlebrot::MAX_ITERATIONS; i++) 
    {
        mTotalIterations += mHistogram[i];
    }   
}

void FractalCreator::drawFractal()
{
    for (int y = 0; y < mHeight; y++) 
    {
        for (int x = 0; x < mWidth; x++) 
        {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = mFractal[y * mWidth + x];
            if (iterations != Mandlebrot::MAX_ITERATIONS) 
            {
                double hue = 0.0;
                for (int i = 0; i <= iterations; i++) {
                    hue += static_cast<double>(mHistogram[i]) / mTotalIterations;
                }
                red = hue * 255;
            }

            mBitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::addZoom(const Zoom& zoom)
{
    mZoomList.add(zoom);
}
    
void FractalCreator::writeBitmap(string name)
{
    mBitmap.write(name);
}