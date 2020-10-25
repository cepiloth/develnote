#include "CompositeBuilder/Person.h"
#include "CompositeBuilder/PersonBuilderBase.h"

PersonBuilder Person::create()
{
    return PersonBuilder{};
}
