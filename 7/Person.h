#ifndef PERSON_H
#define PERSON_H

#include<string>
#include<iostream>
class Person
{
	friend std::istream &read(std::istream&, Person&);
	friend std::ostream &print(std::ostream&, Person&);
private:
	std::string name;
	std::string address;

public:
	Person() = default;
	Person(const std::string &name, const std::string &address): name(name), address(address) {  };
	explicit Person(std::istream &);

	std::string get_Name() const { return name; }
	std::string get_Address() const { return address; }
};
#endif

/*istream &read(istream &is, Person &one)
{
	is >> one.name >> one.address;
	return is;
}

ostream &print(ostream &os, const Person &one)
{
	os << one.get_Name() << " " << one.get_Address() << std::endl;
	return os;
}*/
