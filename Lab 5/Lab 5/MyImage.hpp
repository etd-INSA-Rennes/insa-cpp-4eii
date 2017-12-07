#pragma once

#include <vector>
#include <iostream>
#include <exception>

#include"MyImageIO.hpp"

template<typename Pixel> class MyImage
{
public:

    typedef std::vector<Pixel> data; //enable to change container easily (to test quickly which one is the most efficient for example)

	// the explicit keyword prevents an implicit conversion
	// rule of 3 : no copy ctor, no copy assigment, no dtor

	explicit MyImage(unsigned int height = 0, unsigned int width = 0);

	void resize(unsigned int height, unsigned int width);

public:
    // accessors

     unsigned int size() const { return bitmap_.size(); }
     unsigned int getHeight() const { return height_; }
     unsigned int getWidth() const { return width_; }

     // linear accessors (always by pair)

	 Pixel& operator[](const int i);
	 const Pixel& operator[](const int i) const;

     // image accessors (always by pair)
     // Access to the pixel at the ithe line and jth column (as a 2D matrix)

	 Pixel& operator()(const int i, const int j);
     const Pixel& operator()(const int i, const int j) const ;

     // I/O

     void read(const std::string &filename);
     void write(const std::string &filename) const;

     // classical interface to benefit from all STL algorithm (transform, copy, etc.)

     typedef Pixel value_type;
     typedef typename data::iterator iterator;
     typedef typename data::const_iterator const_iterator;

     iterator begin() { return bitmap_.begin(); }
     const_iterator begin() const { return bitmap_.cbegin(); }
     iterator end() { return bitmap_.end(); }
     const_iterator end() const { return bitmap_.cend(); }


private:

    data bitmap_;
    unsigned int height_;
    unsigned int width_;

};

#include "MyImage.inl"