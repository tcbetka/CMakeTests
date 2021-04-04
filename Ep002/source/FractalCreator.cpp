#include <utility>
using std::pair;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

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
    calculateIteration();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    writeBitmap(name);   
}

void FractalCreator::addZoom(const Zoom& zoom)
{
    mZoomList.add(zoom);
}

void FractalCreator::addRange(double rangeEnd, const RGB& rgb)
{
    mRanges.push_back(rangeEnd * Mandlebrot::MAX_ITERATIONS);
    mColors.push_back(rgb);

    if (mGotFirstRange) {
        mRangeTotals.push_back(0);
    }
    mGotFirstRange = true; 
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

void FractalCreator::calculateRangeTotals()
{
    int rangeIndex = 0;
    for (int i = 0; i < Mandlebrot::MAX_ITERATIONS; i++) {
        int pixels = mHistogram[i];

        if (i >= mRanges[rangeIndex + 1]) {
            rangeIndex++;
        }
        
        mRangeTotals[rangeIndex] += pixels;
    }

    for (int value : mRangeTotals) {
        cout << "Range total: " << value << endl;
    }
}

void FractalCreator::calculateTotalIterations()
{
    for (int i = 0; i < Mandlebrot::MAX_ITERATIONS; i++) {
        mTotalIterations += mHistogram[i];
    }   
}

void FractalCreator::drawFractal()
{
    RGB startColor(0, 0, 0);
    RGB endColor(0, 0, 255);
    RGB colorDiff = endColor - startColor;

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
                
                red = startColor.mRed + colorDiff.mRed * hue;
                green = startColor.mGreen  + colorDiff.mGreen * hue;
                blue = startColor.mBlue + colorDiff.mBlue * hue;
            }

            mBitmap.setPixel(x, y, red, green, blue);
        }
    }
}
   
void FractalCreator::writeBitmap(string name)
{
    mBitmap.write(name);
}