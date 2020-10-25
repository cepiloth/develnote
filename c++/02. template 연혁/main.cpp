#include <string>
#include <iostream>
using namespace std;


// 렌더러의 베이스 클래스는 다음과 같이 정의
struct Renderer
{
	virtual void draw(int x, int y, int width, int height) = 0;
};

struct native : Renderer
{
	void draw(int x, int y, int w, int h) {
		cout << "native" << endl;
	}
};

struct third_party : Renderer
{
	void draw(int x, int y, int w, int h) {
		cout << "native" << endl;
	}
};

struct Scaler
{
protected:
	Renderer& renderer;
	Scaler(Renderer& renderer) : renderer{ renderer } {}

public:
	virtual void draw() = 0;
	virtual void resize(float factor) = 0;
};

class circle : Scaler
{
	int x, y;
	float radius;

public:
	void draw() override {
		cout << "circle" << endl;
	}

	void resize(float factor) override {
		cout << "factor" << endl;
	}

	circle(Renderer& renderer, int x, int y, float radius)
		: Scaler{ renderer }, x{ x }, y{ y }, radius{ radius } {}

};

int main() {

	native rr;
	circle n{ rr, 5,5,5 };
	n.draw();
	n.resize(2);
	n.draw();
	return 0;
}