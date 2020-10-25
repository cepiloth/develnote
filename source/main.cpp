#include <iostream>
using namespace std;

#include "Monostate.h"

void print_monostate(std::string name, int id) {
	cout << name << " id : " << id << endl;
}

int main()
{
	Printer *A = new Printer();
	Printer *B = new Printer();	
	
	return 0;
}