#include "person.h"

std::string person::return_username()
{
	return username;
}

std::string person::return_password()
{
	return password;
}

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

void person::change_username(std::string username)
{
	this -> username = username;
}

void person::change_password(std::string password)
{
	this -> password = password;
}

std::string person::passw()
{
	return password;
}

void person::change(std::string a)
{
	this->password = a;
}

