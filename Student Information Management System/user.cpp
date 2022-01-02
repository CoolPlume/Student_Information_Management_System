#include "user.h"

user::user()
{
	gender = NULL;
	CIM = new course_information_management;
}

user::~user()
{
	delete CIM;
}

user::user(const user& user) :person(user)
{
	this -> last_login_time = user.last_login_time;
	this -> date_of_birth = user.date_of_birth;
	this->gender = user.gender;
	this->actual_name = user.actual_name;
}

void user::change_gender(int gender)
{
	this->gender = gender;
}

int user::return_gender() const
{
	return gender;
}

void user::change_actual_name(const std::string& actual_name)
{
	this->actual_name = actual_name;
}

std::string user::return_actual_name() const
{
	return actual_name;
}

course_information_management* user::revise_course_information_management() const
{
	return CIM;
}

