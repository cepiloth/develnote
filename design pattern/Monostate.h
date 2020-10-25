#ifndef _monostate_h_
#define _monostate_h_

class Printer
{
	static int id;

public:
	int get_id() const { return id; }
	void set_id(int value) { id = value; }

	void print() {
		std::cout << "id" << std::endl;
	}
};
#endif // _monostate_h_