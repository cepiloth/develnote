#pragma once
using namespace std;

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
    Person& person;

    explicit PersonBuilderBase(Person& person)
        : person{ person }
    {
    }

public:
    operator Person() const
    {
        return std::move(person);
    }

    // builder facets

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
    Person p;
public:
    PersonBuilder() : PersonBuilderBase{ p }
    {
    }

};

class PersonJobBuilder : public PersonBuilderBase
{
    typedef PersonJobBuilder Self;
public:
    explicit PersonJobBuilder(Person& person)
        : PersonBuilderBase{ person }
    {
    }

    Self& at(std::string company_name)
    {
        person.company_name = company_name;
        return *this;
    }

    Self& as_a(std::string position)
    {
        person.position = position;
        return *this;
    }

    Self& earning(int annual_income)
    {
        person.annual_income = annual_income;
        return *this;
    }
};

class PersonAddressBuilder : public PersonBuilderBase
{
    typedef PersonAddressBuilder Self;
public:
    explicit PersonAddressBuilder(Person& person)
        : PersonBuilderBase{ person }
    {
    }

    Self& at(std::string street_address)
    {
        person.street_address = street_address;
        return *this;
    }

    Self& with_postcode(std::string post_code)
    {
        person.post_code = post_code;
        return *this;
    }

    Self& in(std::string city)
    {
        person.city = city;
        return *this;
    }
};