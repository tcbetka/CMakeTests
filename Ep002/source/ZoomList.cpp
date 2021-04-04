#include <iostream>
#include "ZoomList.h"

ZoomList::ZoomList(int width, int height) : 
    mWidth(width), 
    mHeight(height)
{

}

void ZoomList::add(const Zoom& zoom)
{
    zooms.push_back(zoom);

    mXcenter += (zoom.mX - mWidth/2) * mScale;
    mYcenter += (zoom.mY - mHeight/2) * mScale;

    mScale *= zoom.mScale;

    std::cout << mXcenter << ", " << mYcenter << ", " << mScale << std::endl;
}

pair<double, double> ZoomList::doZoom(int x, int y)
{
    double xFractal = (x - mWidth/2) * mScale + mXcenter;
    double yFractal = (y - mHeight/2) * mScale + mYcenter;

    return pair<double, double>(xFractal, yFractal);
}
