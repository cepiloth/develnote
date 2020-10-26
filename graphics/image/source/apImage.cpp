#include "apImage.h"
#include "memory.h"

void apImage::init()
{
	if (width_ > 0 && height_ > 0) {
		pixels_ = new byte[width_ * height_];
	}
};

void apImage::cleanup()
{
	delete [] pixels_;
	width_ = 0;
	height_ = 0;
	pixels_ = nullptr;
};

apImage::apImage() 
	: width_(0)
	, height_(0)
	, pixels_(nullptr)
{

};

apImage::apImage(int width, int height)
	: width_(width)
	, height_(height)
	, pixels_(nullptr)
{
	init();
};

apImage::~apImage()
{
	cleanup();
};

apImage::apImage(const apImage& src)
{
	if (src.isValid()) {
		width_ = src.width();
		height_ = src.height();
		
		init();
		memcpy(pixels_, src.pixels_, width_ * height_);
	}
};

/*
@brief: 기존의 데이터를 삭제하고, 원본 이미지를 재생성합니다.
*/
apImage& apImage::operator = (const apImage& src)
{
#if 0

	if (&src != this) {
		cleanup();
		width_ = src.width();
		height_ = src.height();
		
		init();
		memcpy(pixels_, src.pixels_, width_ * height_);
	}

#else

	apImage tmp(src);
	swap(tmp);
	return *this;

#endif
}

template<class T> void swap(T& a, T& b)
{
	T copy(a);
	a = b;
	b = a;
}

void apImage::swap(apImage& src)
{
	::swap(width_, src.width_);
	::swap(height_, src.height_);
	::swap(pixels_, src.pixels_);
}

void apImage::setPixel(int x, int y, byte pixel)
{
	if (x < 0 || y < 0 || x >= width_ || y >= height_ || !isValid()) {
		throw rangeError();
	}

	byte *p = pixels_ + y * width_ + x;
	*p = pixel;
}

byte apImage::getPixel(int x, int y)
{
	if (x < 0 || y < 0 || x >= width_ || y >= height_ || !isValid()) {
		throw rangeError();
	}

	byte *p = pixels_ + y * width_ + x;

	return *p;
}