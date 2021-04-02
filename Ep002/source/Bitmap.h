#ifndef BITMAP_H
#define BITMAP_H

#include <string>
using std::string;

#include <cstdint>
using std::uint8_t;

#include <memory>
using std::unique_ptr;

class Bitmap
{
private:
    int mWidth{0};
    int mHeight{0};
    unique_ptr<uint8_t[]> mPixels{nullptr};

public:
    Bitmap(int width, int height);
    ~Bitmap();

    bool write(string filename);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
};


#endif // BITMAP_H