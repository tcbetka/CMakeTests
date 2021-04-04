#include "ZoomList.h"

 ZoomList::ZoomList(int width, int height) : 
    mWidth(width), 
    mHeight(height)
 {

 }

 void ZoomList::add(const Zoom& zoom)
 {
     zooms.push_back(zoom);
 }

pair<double, double> ZoomList::doZoom(int x, int y)
{
    return pair<double, double>(0,0);
}
