#include "user.h"

user::user()
{

}

user::~user()
{

}

user::user(const user& user) :person(user)
{
	this -> last_login_time = user.last_login_time;
	this -> date_of_birth = user.date_of_birth;
}

int user::oouthout()
{
	last_login_time.record_the_current_time();
	return last_login_time.outhour().count();
}