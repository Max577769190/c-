#include"Person.h"
#include<iostream>
#include<string>

std::istream &read(std::istream &is, Person &one)
{
	is >> one.name >> one.address;
	return is;
}

std::ostream &print(std::ostream &os, Person &one)
{
	os << one.get_Name() << " " << one.get_Address();
	return os;
}

Person::Person(std::istream &is)
{
	read(is, *this);
}
