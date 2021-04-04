#include "RGB.h"

RGB::RGB(double r, double g, double b) :
    mRed(r),
    mGreen(g),
    mBlue(b)
{

}

RGB operator-(const RGB& first, const RGB& second)
{
    double r = first.mRed - second.mRed;
    double g = first.mGreen - second.mGreen;
    double b = first.mBlue - second.mBlue;

    return RGB(r, g, b);
}