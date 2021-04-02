#ifndef BITMAP_FILE_HEADER_H
#define BITMAP_FILE_HEADER_H

#include <cstdint>
using std::int32_t;

// Make C++ align the struct on 2-byte boundaries, otherwise the file will be 
//  unreadable to our program
#pragma pack(2)
struct BitmapFileHeader
{
    // Tell the compiler this is a bitmap file with a 2-byte header
    char header[2]{'B', 'M'};

    // Guarantee our type is 32 bits in size
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};


#endif