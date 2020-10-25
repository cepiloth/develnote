#pragma once
#include <string>
#include <vector>

struct HtmlElement
{
	std::string name;
	std::string text;

	std::vector<HtmlElement> elements;

	HtmlElement() {}
	HtmlElement(const std::string& name, const std::string& text)
		: name(name)
		, text(text) {}

	std::string str(int indent = 0) const 
	{
		// TODO : print
	}
};

/* USAGE
string words[] = {"hello", "world"};
HtmlElement list{"ul", ""};

for (auto w : words)
	list.elements.emplace_back{HtmlElement{"li", w}};

print(list.str().c_str());
*/