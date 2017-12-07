#include "MyImage.hpp"

MyImage::MyImage(unsigned int height, unsigned int width) : height_(height), width_(width) {
	data = data(height * width);
}

void MyImage::resize(unsigned int height, unsigned int width) {
	height_ = height;
	width_ = width;
}

Pixel& MyImage::operator[](const int i) {
	return bitmap_[i];
}

const Pixel& MyImage::operator[](const int i) const {
	return bitmap_[i];
}

Pixel& MyImage::operator()(const int i, const int j) {
	return bitmap[j * width_ + i];
}

const Pixel& MyImage::operator()(const int i, const int j) const {
	return bitmap[j * width_ + i];
}