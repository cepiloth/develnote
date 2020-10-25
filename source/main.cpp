#include <iostream>
using namespace std;

#include "Monostate.h"
#include "HtmlBuilder.h"


int main()
{
	HtmlFluentBuilder builder{ "ui" };
	builder.add_child("li", "hello").add_child("li", "world");
	cout << builder.str() << endl;
	return 0;
}