#include "user.h"

user::user()
{

}

user::~user()
{

}

user::user(const user& user) :person(user)
{

}

int user::oouthout()
{
	last_login_time.record_the_current_time();
	return last_login_time.outhour().count();
}
