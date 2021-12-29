#include "person.h"

person::person()
{
	username = "None";
	password = "None";
	nick_name = "None";
}

person::~person()
{

}

person::person(const person& per)
{
	this -> username = per.username;
	this -> password = per.password;
	this -> nick_name = per.nick_name;
}

std::string person::passw()
{
	return password;
}

void person::change(std::string a)
{
	this->password = a;
}

