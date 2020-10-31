#pragma once

// forward-declare
class CatImpl;

class Cat
{
public:
	Cat();
	virtual ~Cat();

	void setAge(int age);
	void setColor(int color);

	int getAge() const;
	int getColor() const;

private:
	
	CatImpl *impl;
};

/*
* USAGE :
* 
#include <iostream>
#include <string>
using namespace std;

#include "Cat.h"

int main(int argc, char** argv)
{
	Cat* BruceCat = new Cat;
	BruceCat->setAge(38);
	BruceCat->setColor(0xff0000);

	cout << BruceCat->getAge() << endl;
	cout << BruceCat->getColor() << endl;

	return 0;
}
*/