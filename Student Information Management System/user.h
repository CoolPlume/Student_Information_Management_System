#pragma once
#include "person.h"
#include "timer.h"
#include "course_information_management.h"

enum genderType { male, female };

class user :public person
{
private:
	timer last_login_time;
	timer date_of_birth;
	std::string actual_name;
	int gender;
	course_information_management* CIM;
protected:
	
public:
	user();
	virtual ~user();
	user(const user&);
	void change_gender(int);
	int return_gender()const;
	void change_actual_name(const std::string&);
	std::string return_actual_name()const;
	course_information_management* revise_course_information_management()const;
};