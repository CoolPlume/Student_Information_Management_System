#pragma once
#include "person.h"
#include "timer.h"

enum genderType { male, female };

class user :public person
{
private:
	timer last_login_time;
	timer date_of_birth;
	std::string actual_name;
	int gender;
protected:
	
public:
	user();
	virtual ~user();
	user(const user&);
	int oouthout();
};