#include "Cat.h""

class CatImpl
{
public:
	CatImpl()
		:age(0)
		,color(0) {
	}
	~CatImpl() {
		;
	}

	void setAge(int age) {
		this->age = age;
	}
	void setColor(int color) {
		this->color = color;
	}
	int getAge() const {
		return age;
	}
	int getColor() const {
		return color;
	}

private:
	int age;
	int color;
};

Cat::Cat()
	: impl(new CatImpl()) {

}

Cat::~Cat() {
	delete impl;
}

void Cat::setAge(int age) {
	impl->setAge(age);
}
void Cat::setColor(int color) {
	impl->setColor(color);
}

int Cat::getAge() const {
	return impl->getAge();
}

int Cat::getColor() const {
	return impl->getColor();
}