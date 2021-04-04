#ifndef ZOOM_H
#define ZOOM_H

struct Zoom
{
    int mX{0};
    int mY{0};
    double mScale{0.0};

    Zoom(int x, int y, double scale) : mX(x), mY(y), mScale(scale) { }
};


#endif // ZOOM_H