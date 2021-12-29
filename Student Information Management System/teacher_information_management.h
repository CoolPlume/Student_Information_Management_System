#pragma once
#include "teacher.h"
#include "error.h"
#include "user_information_management.h"

class teacher_information_management :public user_information_management
{
private:
	std::forward_list <teacher> teacher_list;
protected:

public:
	teacher_information_management();
	virtual ~teacher_information_management();
};