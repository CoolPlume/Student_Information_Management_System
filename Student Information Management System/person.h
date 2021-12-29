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
	std::string return_username();
	std::string return_password();
	void change_username(std::string);
	void change_password(std::string);
	std::string passw();
	void change(std::string);
};