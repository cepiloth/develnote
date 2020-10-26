#include "Person.h"
#include "PersonBuilderBase.h"

PersonBuilder Person::create()
{
    return PersonBuilder{};
}
