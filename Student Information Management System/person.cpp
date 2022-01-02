#include "person.h"

std::string person::return_username()const
{
	return username;
}

std::string person::return_password()const
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

void person::change_username(const std::string& username)
{
	this->username = username;
}

void person::change_password(const std::string& password)
{
	this->password = password;
}

void person::change_nick_name(const std::string& nick_name)
{
	this->nick_name = nick_name;
}
