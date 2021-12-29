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
	std::string passw();
	void change(std::string);
};