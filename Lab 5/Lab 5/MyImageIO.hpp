
#pragma once

#include <string>


class MyRGBa;
template<typename Pixel> class MyImage;

namespace MyImageIO
{
    enum Format { JPG, BMP, UNKNOWN };

    extern std::string getExtension(const std::string &filename);
    extern Format getFormat(const std::string &filename);

    extern void readJPEG(MyImage<unsigned char> &I, const std::string &filename);
    extern void writeJPEG(const MyImage<unsigned char> &I, const std::string &filename);

    extern void readJPEG(MyImage<MyRGBa> &I, const std::string &filename);
    extern void writeJPEG(const MyImage<MyRGBa> &I, const std::string &filename);

    extern void convert(const MyImage<unsigned char> &src, MyImage<MyRGBa> & dest);
    extern void convert(const MyImage<MyRGBa> &src, MyImage<unsigned char> & dest);
}
