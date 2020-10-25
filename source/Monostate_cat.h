#pragma once
#include <string>

class Cat
{
private:
	static std::string fish;

public:
	std::string get_id() const 
	{ 
		return fish; 
	}
	
	void set_id(std::string &fish) 
	{ 
		this->fish = fish; 
	}
};