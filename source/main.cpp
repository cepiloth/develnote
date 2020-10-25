#include <iostream>

#include "Monostate.h"

int main()
{
	Printer A;
	Printer B;

	A.set_id(1);
	A.print();
	B.print();

	B.set_id(2);
	B.print();
	return 0;
}