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
	void teacher_interface(int);
	void student_interface(int);
	void add_manager();
	void add_student();
	void add_teacher();
	void change_password(int);
	void change_nick_name(int);
	void select_subjects(int);
};