#pragma once
#include "user_information_management.h"
#include "student.h"
#include "error.h"

class student_information_management :public user_information_management
{
private:
	std::forward_list <student> student_list;
protected:

public:
	student_information_management();
	virtual ~student_information_management();
};