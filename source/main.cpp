#include <iostream>
using namespace std;

#include "Monostate.h"
#include "HtmlBuilder.h"


int main()
{
	HtmlBuilder builder{ "ui" };
	builder.add_child("li", "hello");
	builder.add_child("li", "world");
	cout << builder.str() << endl;
	return 0;
}