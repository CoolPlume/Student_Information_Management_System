#pragma once
#include "user_interface.h"

enum class user_Type
{
	administrator = 1,
	teacher = 2,
	student = 3
};

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
			return;
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
			wrong_selection(static_cast<int>(error_code_Type::Subscript_out_of_bounds), wrong_selection_flag);
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
			if (SIM->login_decision(username, password))
			{
				cout << "登录成功！" << endl;
				student_interface(static_cast<int>(user_Type::student));
			}
			else
			{
				login_failed(static_cast<int>(error_code_Type::Wrong_user_name_or_password), login_failed_flag);
			}
			break;
		}
		case 'T':
		{
			login_failed_flag = false;
			if (TIM->login_decision(username, password))
			{
				cout << "登录成功！" << endl;
				teacher_interface(static_cast<int>(user_Type::teacher));
			}
			else
			{
				login_failed(static_cast<int>(error_code_Type::Wrong_user_name_or_password), login_failed_flag);
			}
			break;
		}
		case 'a':
		{
			login_failed_flag = false;
			if (AIM->login_decision(username, password))
			{
				cout << "登录成功！" << endl;
				administrator_interface();
			}
			else
			{
				login_failed(static_cast<int>(error_code_Type::Wrong_user_name_or_password), login_failed_flag);
			}
			break;
		}
		default:
		{
			login_failed(static_cast<int>(error_code_Type::User_type_error), login_failed_flag);
			break;
		}
		}
	} while (login_failed_flag);
}

void user_interface::administrator_interface()
{
	using std::cin, std::cout, std::endl;
	cout << endl
		<< "你好，管理员：" << AIM->return_currently_logged_in_administrator().return_username() << endl << endl;
	system("pause");
	do//UNDONE 面板跳转
	{
		cout << endl;
		cout << "********************************************" << endl
			<< "======>>       管理员操纵面板       <<======" << endl
			<< endl
			<< "      *      [1]添加管理员           *      " << endl
			<< "      *      [2]添加教师             *      " << endl
			<< "      *      [3]添加学生             *      " << endl
			<< "      *      [4]修改密码             *      " << endl
			<< "      *      [5]切换教师面板         *      " << endl
			<< "      *      [6]切换学生面板         *      " << endl
			<< "      *      [7]新功能会在这里       *      " << endl
			<< "      *      [0]退出                 *      " << endl
			<< endl
			<< "********************************************" << endl << endl;

		bool wrong_selection_flag = false;
		int select;
		do//UNDONE
		{
			cout << "请选择您的操作（0-6）：";
			cin >> select;
			switch (select)
			{
			case 0:
			{
				wrong_selection_flag = false;
				return;
				break;
			}
			case 1:
			{
				wrong_selection_flag = false;
				add_manager();
				break;
			}
			case 2:
			{
				wrong_selection_flag = false;
				add_teacher();
				break;
			}
			case 3:
			{
				wrong_selection_flag = false;
				add_student();
				break;
			}
			case 4:
			{
				wrong_selection_flag = false;
				change_password(static_cast<int>(user_Type::administrator));
				break;
			}
			case 5:
			{
				wrong_selection_flag = false;
				teacher_interface(static_cast<int>(user_Type::administrator));
				break;
			}
			case 6:
			{
				wrong_selection_flag = false;
				student_interface(static_cast<int>(user_Type::administrator));
				break;
			}
			default:
			{
				wrong_selection(static_cast<int>(error_code_Type::Subscript_out_of_bounds), wrong_selection_flag);
				break;
			}
			}
		} while (wrong_selection_flag);
	} while (true);
}

void user_interface::teacher_interface(int user_type)//TODO
{
	using std::cin, std::cout, std::endl;
	if (user_type == static_cast<int>(user_Type::teacher))
	{
		cout << endl
			<< "你好，教师：" << TIM->return_currently_logged_in_teacher().return_nick_name() << endl << endl;
		system("pause");
	}

	cout << endl;
	cout << "********************************************" << endl
		<< "======>>       教师操纵面板       <<======" << endl;
	cout << endl
		<< "      *      [1]学生查询             *      " << endl
		<< "      *      [2]导出本班学生         *      " << endl
		<< "      *      [3]导出上课课表         *      " << endl
		<< "      *      [4]导出本班课表         *      " << endl
		<< "      *      [5]修改密码             *      " << endl
		<< "      *      [6]修改昵称             *      " << endl
		<< "      *      [7]新功能会在这里       *      " << endl
		<< "      *      [0]退出                 *      " << endl << endl
		<< "********************************************" << endl << endl;

	bool wrong_selection_flag = false;
	int select;
	do
	{
		cout << "请选择您的操作（0-7）：";
		cin >> select;
		switch (select)
		{
		case 0:
		{
			wrong_selection_flag = false;
			return;
			break;
		}
		case 5:
		{
			wrong_selection_flag = false;
			if (user_type != static_cast<int>(user_Type::teacher))
			{
				cout << "错误！请使用教师账户来进行此操作。" << endl;
				system("pause");
			}
			else
			{
				change_password(static_cast<int>(user_Type::teacher));
			}
			break;
		}
		case 6:
		{
			wrong_selection_flag = false;
			if (user_type != static_cast<int>(user_Type::teacher))
			{
				cout << "错误！请使用教师账户来进行此操作。" << endl;
				system("pause");
			}
			else
			{
				change_nick_name(static_cast<int>(user_Type::teacher));
			}
			break;
		}
		default:
		{
			wrong_selection(static_cast<int>(error_code_Type::Subscript_out_of_bounds), wrong_selection_flag);
			break;
		}
		}
	} while (wrong_selection_flag);
}

void user_interface::student_interface(int user_type)//TODO
{
	using std::cin, std::cout, std::endl;
	if (user_type == static_cast<int>(user_Type::student))
	{
		cout << endl
			<< "你好，学生：" << SIM->return_currently_logged_in_student().return_nick_name() << endl << endl;
		system("pause");
	}

	cout << endl;
	cout << "********************************************" << endl
		<< "======>>       学生操纵面板       <<======" << endl;
	cout << endl
		<< "      *      [1]成绩查询             *      " << endl
		<< "      *      [2]导出课表             *      " << endl
		<< "      *      [3]修改密码             *      " << endl
		<< "      *      [4]修改昵称             *      " << endl
		<< "      *      [5]新功能会在这里       *      " << endl
		<< "      *      [0]退出                 *      " << endl << endl
		<< "********************************************" << endl << endl;

	bool wrong_selection_flag = false;
	int select;
	do
	{
		cout << "请选择您的操作（0-5）：";
		cin >> select;
		switch (select)
		{
		case 0:
		{
			wrong_selection_flag = false;
			return;
			break;
		}
		case 3:
		{
			wrong_selection_flag = false;
			if (user_type != static_cast<int>(user_Type::student))
			{
				cout << "错误！请使用学生账户来进行此操作。" << endl;
				system("pause");
			}
			else
			{
				change_password(static_cast<int>(user_Type::student));
			}
			break;
		}
		case 4:
		{
			wrong_selection_flag = false;
			wrong_selection_flag = false;
			if (user_type != static_cast<int>(user_Type::student))
			{
				cout << "错误！请使用学生账户来进行此操作。" << endl;
				system("pause");
			}
			else
			{
				change_nick_name(static_cast<int>(user_Type::student));
			}
			break;
		}
		default:
		{
			wrong_selection(static_cast<int>(error_code_Type::Subscript_out_of_bounds), wrong_selection_flag);
			break;
		}
		}
	} while (wrong_selection_flag);
}

void user_interface::add_manager()
{
	using std::cin, std::cout, std::endl;
	administrator* admin = new administrator;
	cout << endl
		<< "======>>       添加管理员       <<======" << endl << endl
		<< "请在下方输入要添加的信息" << endl;

	std::string username;
	bool incorrect_username_format_flag = false;
	bool stop_add_flag = false;
	do
	{
		do
		{
			cout << "请输入用户名（管理员用户名必须以字母 a 开头）：";
			cin >> username;
			if (username[0] != 'a')
			{
				incorrect_username_format_flag = false;
				stop_add_flag = add_information_failed(static_cast<int>(error_code_Type::Incorrect_username_format), incorrect_username_format_flag);
			}
			else
			{
				admin->change_username(username);
				incorrect_username_format_flag = false;
			}
		} while (incorrect_username_format_flag);
		if (stop_add_flag)
		{
			break;
		}
		stop_add_flag = false;
		bool inconsistent_passwords_flag = false;
		do
		{
			cout << "请输入密码：";
			std::string password1, password2;
			cin >> password1;
			cout << "请重复密码：";
			cin >> password2;
			if (password1 != password2)
			{
				inconsistent_passwords_flag = false;
				stop_add_flag = add_information_failed(static_cast<int>(error_code_Type::The_two_passwords_are_inconsistent), inconsistent_passwords_flag);
			}
			else
			{
				admin->change_password(password1);
				inconsistent_passwords_flag = false;
			}
		} while (inconsistent_passwords_flag);
		if (stop_add_flag)
		{
			break;
		}
		cout << "添加成功！" << endl;
		AIM->add_manager(*admin);
	} while (false);
	delete admin;
}

void user_interface::add_student()
{
	using std::cin, std::cout, std::endl;
	student* stu = new student;
	cout << endl
		<< "======>>       添加学生       <<======" << endl << endl
		<< "请在下方输入要添加的信息" << endl;

	do
	{
		std::string actual_name;
		bool stop_add_flag = false;
		cout << "请输入学生姓名：";
		cin >> actual_name;
		stu->change_actual_name(actual_name);

		bool inconsistent_passwords_flag = false;
		do
		{
			cout << "请输入密码：";
			std::string password1, password2;
			cin >> password1;
			cout << "请重复密码：";
			cin >> password2;
			if (password1 != password2)
			{
				inconsistent_passwords_flag = false;
				stop_add_flag = add_information_failed(static_cast<int>(error_code_Type::The_two_passwords_are_inconsistent), inconsistent_passwords_flag);
			}
			else
			{
				stu->change_password(password1);
				inconsistent_passwords_flag = false;
			}
		} while (inconsistent_passwords_flag);
		if (stop_add_flag)
		{
			break;
		}

		int gender;
		bool wrong_selection_flag = false;
		do
		{
			cout << "请输入性别（0：男；1：女）：";
			cin >> gender;
			switch (gender)
			{
			case 0:
			{
				__fallthrough;
			}
			case 1:
			{
				wrong_selection_flag = false;
				stu->change_gender(gender);
				break;
			}
			default:
			{
				wrong_selection(static_cast<int>(error_code_Type::Subscript_out_of_bounds), wrong_selection_flag);
				break;
			}
			}
		} while (wrong_selection_flag);

		const std::string name = "S" + std::to_string((SIM->return_student_list_size()) + 1);
		stu->change_username(name);
		stu->change_nick_name(stu->return_username());

		cout << "添加成功！" << endl;
		SIM->add_student(*stu);
	} while (false);
	delete stu;
}

void user_interface::add_teacher()
{
	using std::cin, std::cout, std::endl;
	teacher* tea = new teacher;
	cout << endl
		<< "======>>       添加教师       <<======" << endl << endl
		<< "请在下方输入要添加的信息" << endl;

	do
	{
		std::string actual_name;
		bool stop_add_flag = false;
		cout << "请输入教师姓名：";
		cin >> actual_name;
		tea->change_actual_name(actual_name);

		bool inconsistent_passwords_flag = false;
		do
		{
			cout << "请输入密码：";
			std::string password1, password2;
			cin >> password1;
			cout << "请重复密码：";
			cin >> password2;
			if (password1 != password2)
			{
				inconsistent_passwords_flag = false;
				stop_add_flag = add_information_failed(static_cast<int>(error_code_Type::The_two_passwords_are_inconsistent), inconsistent_passwords_flag);
			}
			else
			{
				tea->change_password(password1);
				inconsistent_passwords_flag = false;
			}
		} while (inconsistent_passwords_flag);
		if (stop_add_flag)
		{
			break;
		}

		int gender;
		bool wrong_selection_flag = false;
		do
		{
			cout << "请输入性别（0：男；1：女）：";
			cin >> gender;
			switch (gender)
			{
			case 0:
			{
				__fallthrough;
			}
			case 1:
			{
				wrong_selection_flag = false;
				tea->change_gender(gender);
				break;
			}
			default:
			{
				wrong_selection(static_cast<int>(error_code_Type::Subscript_out_of_bounds), wrong_selection_flag);
				break;
			}
			}
		} while (wrong_selection_flag);

		const std::string name = "T" + std::to_string((TIM->return_teacher_list_size()) + 1);
		tea->change_username(name);
		tea->change_nick_name(tea->return_username());

		cout << "添加成功！" << endl;
		TIM->add_teacher(*tea);
	} while (false);
	delete tea;
}

void user_interface::change_password(int user_type)
{
	using std::cin, std::cout, std::endl;
	cout << endl
		<< "======>>       修改密码       <<======" << endl << endl;
	do
	{
		bool stop_add_flag = false;
		bool inconsistent_passwords_flag = false;
		do
		{
			cout << "请输入修改后的密码：";
			std::string password1, password2;
			cin >> password1;
			cout << "请重复密码：";
			cin >> password2;
			if (password1 != password2)
			{
				inconsistent_passwords_flag = false;
				stop_add_flag = add_information_failed(static_cast<int>(error_code_Type::The_two_passwords_are_inconsistent), inconsistent_passwords_flag);
			}
			else
			{
				switch(user_type)
				{
				case static_cast<int>(user_Type::administrator):
				{
					if (AIM->return_currently_logged_in_administrator().return_super_administrator() == true)
					{
						cout << "超级管理员不允许修改密码！" << endl;
					}
					else
					{
						AIM->revise_currently_logged_in_administrator()->change_password(password1);
						cout << "修改成功！" << endl;
					}
					break;
				}
				case static_cast<int>(user_Type::teacher):
				{
					TIM->revise_currently_logged_in_teacher()->change_password(password1);
					cout << "修改成功！" << endl;
					break;
				}
				case static_cast<int>(user_Type::student):
				{
					SIM->revise_currently_logged_in_student()->change_password(password1);
					cout << "修改成功！" << endl;
					break;
				}
				}
				inconsistent_passwords_flag = false;
			}
		} while (inconsistent_passwords_flag);
		if (stop_add_flag)
		{
			cout << "取消修改！" << endl;
			break;
		}
	} while (false);
}

void user_interface::change_nick_name(int user_type)
{
	using std::cin, std::cout, std::endl;
	cout << endl
		<< "======>>       修改昵称       <<======" << endl << endl;

	std::string nick_name;
	cout << "请输入修改后的昵称：";
	cin >> nick_name;
	switch(user_type)
	{
		case static_cast<int>(user_Type::teacher):
		{
			TIM->revise_currently_logged_in_teacher()->change_nick_name(nick_name);
			break;
		}
		case static_cast<int>(user_Type::student):
		{
			SIM->revise_currently_logged_in_student()->change_nick_name(nick_name);
			break;
		}
	}
}
