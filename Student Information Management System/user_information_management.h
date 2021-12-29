#pragma once
#include "user.h"
#include <forward_list>
#include <fstream>

class user_information_management
{
private:
	std::forward_list <user> menber_list;
protected:

public:
	user_information_management();
	virtual ~user_information_management();
};