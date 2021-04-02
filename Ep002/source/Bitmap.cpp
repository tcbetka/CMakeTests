#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

Bitmap::Bitmap(int width, int height) : 
    mWidth(width), 
    mHeight(height),
    mPixels(new uint8_t[width * height * 3]{0}) // 3 bytes per pixel (24-bit color)
{

}

Bitmap::~Bitmap()
{

}

bool Bitmap::write(string filename)
{
    // Write file header to the file
    BitmapFileHeader fileHeader;
    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (mWidth * mHeight * 3);
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    // Write info header to the file 
    BitmapInfoHeader infoHeader;
    infoHeader.width = mWidth;
    infoHeader.height = mHeight;

    // Write data to the file
    return false;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{

}