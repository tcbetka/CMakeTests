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

}

Bitmap::~Bitmap()
{
}

bool Bitmap::write(string filename)
{

    // Write file header to the file
    BitmapFileHeader fileHeader;
    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (this->mWidth * this->mHeight * 3);
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
    outFile.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    outFile.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
    outFile.write(reinterpret_cast<char*>(mPixels.get()), sizeof(mWidth * mHeight * 3));

    outFile.close();
    return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{

}