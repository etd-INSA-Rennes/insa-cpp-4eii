#include "MyImageIO.hpp"
#include "MyImage.hpp"
#include "MyRGBa.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <exception>
#include <jpeglib.h>
#include <jerror.h>

using namespace std;


#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif

namespace MyImageIO {

    // return the extension of the file including the dot
    string getExtension(const std::string &filename)
    {
        // extract the extension
        size_t dot = filename.find_last_of(".");
        string ext = filename.substr(dot, filename.size()-1);
        return ext;
    }

    //return the format compression
    Format getFormat(const std::string &filename)
    {

        string ext = getExtension(filename);

        if (ext.compare(".BMP") == 0) return BMP;
        if (ext.compare(".bmp") == 0) return BMP;
        if (ext.compare(".JPG") == 0) return JPG;
        if (ext.compare(".jpg") == 0) return JPG;
        if (ext.compare(".JPEG") == 0) return JPG;
        if (ext.compare(".jpeg") == 0) return JPG;

        return UNKNOWN;
    }


    void readJPEG(MyImage<unsigned char> &I, const std::string &filename)
    {
        struct jpeg_decompress_struct cinfo;
        struct jpeg_error_mgr jerr;
        FILE *file = NULL;

        cinfo.err = jpeg_std_error(&jerr);
        jpeg_create_decompress(&cinfo);


        file = fopen(filename.c_str(), "rb");

        if (file == NULL) {
            throw (ios_base::failure("Cannot write file in readJPEG()")) ;
        }

        jpeg_stdio_src(&cinfo, file);
        jpeg_read_header(&cinfo, TRUE);

        unsigned int width = cinfo.image_width;
        unsigned int height = cinfo.image_height;

        if ( (width != I.getWidth()) || (height != I.getHeight()) )
            I.resize(height,width);

        jpeg_start_decompress(&cinfo);

        unsigned int rowbytes = cinfo.output_width * (unsigned int)(cinfo.output_components);
        JSAMPARRAY buffer = (*cinfo.mem->alloc_sarray)
            ((j_common_ptr) &cinfo, JPOOL_IMAGE, rowbytes, 1);

        if (cinfo.out_color_space == JCS_RGB) {
            int i = 0; // same as cinfo.output_scanline
            while (cinfo.output_scanline < cinfo.output_height) {
                jpeg_read_scanlines(&cinfo, buffer, 1);
                for (unsigned int j = 0; j < width; j++) {
                    I[i*width+j]=MyRGBa(buffer[0][j * 3], buffer[0][j * 3 + 1], buffer[0][j * 3 + 2], 0).getGreyValue();
                }
                ++i;
            }
        }
        else if (cinfo.out_color_space == JCS_GRAYSCALE)
        {
            unsigned int row;
            while (cinfo.output_scanline<cinfo.output_height)
            {
                row = cinfo.output_scanline;
                jpeg_read_scanlines(&cinfo,buffer,1);
                memcpy(&I[row*width], buffer[0], rowbytes);
            }
        }

        jpeg_finish_decompress(&cinfo);
        jpeg_destroy_decompress(&cinfo);
        fclose(file);
    }


    void writeJPEG(const MyImage<unsigned char> &I, const std::string &filename)
    {
        struct jpeg_compress_struct cinfo;
        struct jpeg_error_mgr jerr;
        FILE *file = NULL;

        cinfo.err = jpeg_std_error(&jerr);
        jpeg_create_compress(&cinfo);

        file = fopen(filename.c_str(), "wb");

        if (file == NULL) {
            throw (ios_base::failure("Cannot write file in writeJPEG()")) ;
        }

        unsigned int width = I.getWidth();
        unsigned int height = I.getHeight();

        jpeg_stdio_dest(&cinfo, file);

        cinfo.image_width = width;
        cinfo.image_height = height;
        cinfo.input_components = 1;
        cinfo.in_color_space = JCS_GRAYSCALE;

        jpeg_set_defaults(&cinfo);

        jpeg_set_quality (&cinfo, 100, TRUE);
        jpeg_start_compress(&cinfo,TRUE);

        vector<unsigned char> line(width);
        unsigned char *ptr = &line[0];
        int nrow = 0;
        while (cinfo.next_scanline < cinfo.image_height)
        {
            for (unsigned int j = 0; j < width; j++)
            {
                line[j] = I[nrow*width + j];
            }
            jpeg_write_scanlines(&cinfo, &ptr, 1);
            ++nrow;
        }

        jpeg_finish_compress(&cinfo);
        jpeg_destroy_compress(&cinfo);
        fclose(file);
    }
	
    void readJPEG(MyImage<MyRGBa> &I, const std::string &filename)
    {
        struct jpeg_decompress_struct cinfo;
        struct jpeg_error_mgr jerr;
        FILE *file = NULL;

        cinfo.err = jpeg_std_error(&jerr);
        jpeg_create_decompress(&cinfo);


        file = fopen(filename.c_str(), "rb");


        if (file == NULL) {
            throw (ios_base::failure("Cannot write file in readJPEG()")) ;
        }

        jpeg_stdio_src(&cinfo, file);

        jpeg_read_header(&cinfo, TRUE);

        unsigned int width = cinfo.image_width;
        unsigned int height = cinfo.image_height;

        if ( (width != I.getWidth()) || (height != I.getHeight()) )
            I.resize(height,width);

        jpeg_start_decompress(&cinfo);

        unsigned int rowbytes = cinfo.output_width * (unsigned int)(cinfo.output_components);
        JSAMPARRAY buffer = (*cinfo.mem->alloc_sarray)
            ((j_common_ptr) &cinfo, JPOOL_IMAGE, rowbytes, 1);

        if (cinfo.out_color_space == JCS_RGB)
        {
            int i = 0; // same as cinfo.output_scanline
            while (cinfo.output_scanline < cinfo.output_height)
            {
                jpeg_read_scanlines(&cinfo, buffer, 1);
                for (unsigned int j = 0; j < width; j++) {
                    I[i*width+j] = MyRGBa(buffer[0][j * 3], buffer[0][j * 3 + 1], buffer[0][j * 3 + 2], 0);
                }
                ++i;
            }
        } else if (cinfo.out_color_space == JCS_GRAYSCALE) {
            int i = 0;
            while (cinfo.output_scanline < cinfo.output_height)
            {
                jpeg_read_scanlines(&cinfo, buffer, 1);
                for (unsigned int j = 0; j < width; j++) {
                    I[i*width+j] = MyRGBa(buffer[0][j]);
                }
                ++i;
            }
        }

        jpeg_finish_decompress(&cinfo);
        jpeg_destroy_decompress(&cinfo);
        fclose(file);
    }


    void writeJPEG(const MyImage<MyRGBa> &I, const std::string &filename)
    {
        struct jpeg_compress_struct cinfo;
        struct jpeg_error_mgr jerr;
        FILE *file;

        cinfo.err = jpeg_std_error(&jerr);
        jpeg_create_compress(&cinfo);

        file = fopen(filename.c_str(), "wb");

        if (file == NULL) {
            throw (ios_base::failure("Cannot write file in writeJPEG()")) ;
        }

        unsigned int width = I.getWidth();
        unsigned int height = I.getHeight();

        jpeg_stdio_dest(&cinfo, file);

        cinfo.image_width = width;
        cinfo.image_height = height;
        cinfo.input_components = 3;
        cinfo.in_color_space = JCS_RGB;
        jpeg_set_defaults(&cinfo);

        jpeg_set_quality (&cinfo, 100, FALSE);
        jpeg_start_compress(&cinfo,TRUE);

        vector<unsigned char> line(3 * width);
        unsigned char *ptr = &line[0];
        int nrow = 0;
        while (cinfo.next_scanline < cinfo.image_height)
        {
            for (unsigned int j = 0; j < width; j++)
            {
                line[j * 3] = I[nrow*width + j].getR();
                line[j * 3 + 1] = I[nrow*width + j].getG();
                line[j * 3 + 2] = I[nrow*width + j].getB();
            }
            jpeg_write_scanlines(&cinfo, &ptr, 1);
            ++nrow;
        }

        jpeg_finish_compress(&cinfo);
        jpeg_destroy_compress(&cinfo);
        fclose(file);
    }
	

}//end MyImageIO namespace
