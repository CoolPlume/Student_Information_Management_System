#pragma once
#include "user_interface.h"

user_interface::user_interface()
{
	SIM = new student_information_management;
	TIM = new teacher_information_management;
	AIM = new administrator_information_management;
}

user_interface::~user_interface()
{
	delete SIM;
	delete TIM;
	delete AIM;
}

void user_interface::welcome()
{
	using std::cout, std::endl, std::cin;
	cout << "********************************************" << endl
		<< "----------欢迎使用学生信息管理系统----------" << endl << endl
		<< "     *    [1]登录                     *     " << endl
		<< "     *    [0]退出                     *     " << endl << endl
		<< "********************************************" << endl << endl;
	int select;
	bool wrong_selection_flag = false;
	do
	{
		cout << "请选择您的操作（0-1）：";
		cin >> select;
		switch (select)
		{
		case 0:
		{
			wrong_selection_flag = false;
			exit(0);
			break;
		}
		case 1:
		{
			wrong_selection_flag = false;
			login();
			break;
		}
		default:
		{
			wrong_selection((int)error_code_Type::Subscript_out_of_bounds, wrong_selection_flag);
			break;
		}
		}
	} while (wrong_selection_flag);
}

void user_interface::login()
{
	using std::cin, std::cout, std::endl;
	cout << endl;
	cout << "======>>     用户登录     <<======" << endl << endl;
	bool login_failed_flag = false;
	do
	{
		cout << "请输入用户名：";
		std::string username;
		cin >> username;
		cout << "请输入密码：";
		std::string password;
		cin >> password;
		switch (username[0])//UNDONE
		{
		case 'S':
		{
			login_failed_flag = false;
			break;
		}
		case 'T':
		{
			login_failed_flag = false;
			break;
		}
		case 'a':
		{
			login_failed_flag = false;
			if (AIM->login_decision(username, password))
			{

			}
			else
			{
				login_failed((int)error_code_Type::Wrong_user_name_or_password, login_failed_flag);
			}
			break;
		}
		default:
		{
			login_failed((int)error_code_Type::User_type_error, login_failed_flag);
			break;
		}
		}
	} while (login_failed_flag);
}
