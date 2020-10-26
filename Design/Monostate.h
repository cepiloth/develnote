#ifndef _monostate_h_
#define _monostate_h_

class Printer
{
private:
	static int id;

public:
	int get_id() const { return id; }
	void set_id(int value) { id = value; }
};

#endif // _monostate_h_