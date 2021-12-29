#pragma once
#include "error.h"
#include "student_information_management.h"
#include "teacher_information_management.h"
#include "administrator_information_management.h"

class user_interface
{
private:
	student_information_management* SIM;
	teacher_information_management* TIM;
	administrator_information_management* AIM;
protected:

public:
	user_interface();
	~user_interface();
};