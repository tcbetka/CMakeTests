#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

Bitmap::Bitmap(int width, int height) : 
    mWidth(width), 
    mHeight(height),
    mPixels(new uint8_t[width * height * 3]) // 3 bytes per pixel (24-bit color)
{
    //cout << "mPixels = " << mWidth * mHeight * 3 << " bytes" << endl;
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
    ofstream outFile;
    outFile.open(filename, std::ios::out | std::ios::binary);
    if (!outFile.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return false;
    }

    // Write our file header first
    outFile.write((char*)&fileHeader, sizeof(fileHeader));
    outFile.write((char*)&infoHeader, sizeof(infoHeader));
    outFile.write((char*)mPixels.get(), mWidth * mHeight * 3);

    outFile.close();
    return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
    // Get a pointer to the memory managed by our unique_ptr
    uint8_t* pPixel = mPixels.get();

    pPixel += (y * 3) * mWidth + (x * 3);

    // These are in reverse order as it's in LE byte order
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}