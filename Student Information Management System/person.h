#pragma once
#include <string>
#include "course_information_management.h"

class person
{
private:
	std::string username;
	std::string password;
protected:
	std::string nick_name;
public:
	person();
	virtual ~person();
	person(const person&);
	std::string return_username()const;
	std::string return_password()const;
	std::string return_nick_name()const;
	void change_username(const std::string&);
	void change_password(const std::string&);
	void change_nick_name(const std::string&);
};