#pragma once
#include "error.h"
#include "student_information_management.h"
#include "teacher_information_management.h"
#include "administrator_information_management.h"
#include <string>

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
	void welcome();
	void login();
	void administrator_interface();
	void teacher_interface();
	void student_interface();
};