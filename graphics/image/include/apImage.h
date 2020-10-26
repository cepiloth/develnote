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
	// �̹��� �����Ͱ� ��ȿ���� �׽�Ʈ �մϴ�.

	int width() const { return width_; }
	int height() const { return height_; }

	// ���� Ŭ����
	class rangeError {};

private:
	void init();
	void cleanup();

	int width_;
	int height_;
	byte* pixels_;
};