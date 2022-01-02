#pragma once
#include "user_information_management.h"
#include "student.h"
#include "error.h"

class student_information_management :public user_information_management
{
private:
	std::list <student> student_list;
	student* currently_logged_in_student;
protected:

public:
	student_information_management();
	virtual ~student_information_management();
	bool login_decision(const std::string&, const std::string&);
	student return_currently_logged_in_student()const;
	void add_student(const student&);
};