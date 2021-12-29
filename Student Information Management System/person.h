#pragma once
#include <string>

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
	void change_username(const std::string&);
	void change_password(const std::string&);
	std::string passw();
	void change(std::string);
};