#include <utility>
using std::pair;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <cassert>

#include "FractalCreator.h"

FractalCreator::FractalCreator(int width, int height) :
    mWidth(width),
    mHeight(height),
    mHistogram(new int[Mandlebrot::MAX_ITERATIONS]{0}),
    mFractal(new int[mWidth * mHeight]{0}),
    mBitmap(mWidth, mHeight),
    mZoomList(mWidth, mHeight)
{
    mZoomList.add(Zoom(mWidth/2, mHeight/2, 4.0/mWidth));
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

int FractalCreator::getRange(int iterations) const
{
    int range{0};

    for (int i = 1; i < mRanges.size(); i++) {
        range = i;

        if (mRanges[i] > iterations) {
            break;
        }
    }

    // Shift back to a zero-based index
    range--;

    assert(range > -1);
    assert(range < mRanges.size());

    return range;
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
}

void FractalCreator::calculateTotalIterations()
{
    for (int i = 0; i < Mandlebrot::MAX_ITERATIONS; i++) {
        mTotalIterations += mHistogram[i];
    }   
}

void FractalCreator::drawFractal()
{
    for (int y = 0; y < mHeight; y++) 
    {
        for (int x = 0; x < mWidth; x++) 
        {
            int iterations = mFractal[(y * mWidth) + x];
            int range = getRange(iterations);
            int rangeTotal = mRangeTotals[range];
            int rangeStart = mRanges[range];

            RGB& startColor = mColors[range];
            RGB& endColor = mColors[range+1];
            RGB colorDiff = endColor - startColor;

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            
            if (iterations != Mandlebrot::MAX_ITERATIONS) 
            {
                int totalPixels = 0;

                for (int i = rangeStart; i <= iterations; i++) {
                    totalPixels += mHistogram[i];
                }
                
                red = startColor.mRed + 
                    (colorDiff.mRed * static_cast<double>(totalPixels) / rangeTotal);
                green = startColor.mGreen  + 
                    (colorDiff.mGreen * static_cast<double>(totalPixels) / rangeTotal);
                blue = startColor.mBlue + 
                    `(colorDiff.mBlue * static_cast<double>(totalPixels) / rangeTotal);
            }

            mBitmap.setPixel(x, y, red, green, blue);
        }
    }
}

   
void FractalCreator::writeBitmap(string name)
{
    mBitmap.write(name);
}