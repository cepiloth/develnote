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
		std::string s;
		for (auto e : elements) {
			s += e.name;
			s += " tag : ";
			s += e.text;
			s += "\n";
		}
		return s;
	}
};

/* USAGE
string words[] = {"hello", "world"};
HtmlElement list{"ul", ""};

for (auto w : words)
	list.elements.emplace_back{HtmlElement{"li", w}};

print(list.str().c_str());
*/

/* 단순한 빌더 패턴*/
struct HtmlBuilder
{
	HtmlElement root;

	HtmlBuilder(std::string root_name) { root.name = root_name; }

	void add_child(std::string child_name, std::string child_text) {
		HtmlElement e{ child_name, child_text };
		root.elements.emplace_back(e);
	}

	std::string str() { 
		return root.str(); 
	}
};