#pragma once
#include "person.h"
#include "timer.h"

class user :public person
{
private:
	timer last_login_time;
protected:
	
public:
	user();
	virtual ~user();
	user(const user&);
	int oouthout();
};