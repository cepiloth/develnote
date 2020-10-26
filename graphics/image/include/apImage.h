#pragma once

typedef unsigned char byte;

class apImage
{
public:
	apImage();
	apImage(int width, int height);
	~apImage();

	apImage(const apImage& src);
	apImage& operator = (const apImage& src);

	void swap(apImage& src);
	void setPixel(int x, int y, byte pixel);
	byte getPixel(int x, int y);

	bool isValid() const { return pixels_ != nullptr; }
	// 이미지 데이터가 유효한지 테스트 합니다.

	int width() const { return width_; }
	int height() const { return height_; }

	// 예외 클래스
	class rangeError {};

private:
	void init();
	void cleanup();

	int width_;
	int height_;
	byte* pixels_;
};