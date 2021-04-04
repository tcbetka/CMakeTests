#ifndef ZOOM_LIST_H
#define ZOOM_LIST_H

#include <vector>
using std::vector;

#include <utility>
using std::pair;

#include "Zoom.h"


class ZoomList
{
private:
    double mXcenter{0.0};
    double mYcenter{0.0};
    double mScale{1.0};
    int mWidth{0};
    int mHeight{0};
    vector<Zoom> zooms;

public:
    ZoomList(int width, int height);

    void add(const Zoom& zoom);
    pair<double, double> doZoom(int x, int y);
};

#endif // ZOOM_LIST_H