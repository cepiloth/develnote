#include <iostream>
using namespace std;

#include "SingleTon.h"
#include "Monostate.h"

#include "HtmlBuilder.h"
#include "EmailBuilder.h"

#include "CompositeBuilder/PersonBuilderBase.h"
#include "CompositeBuilder/Person.h"

int main()
{
	Person p = Person::create()
		.lives().at("123 London Road")
		.with_postcode("SW1 1GB")
		.in("London")
		.works().at("PragmaSoft")
		.as_a("Consultant")
		.earning(10e6);

	return 0;
}