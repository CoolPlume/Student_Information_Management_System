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
		<< "----------��ӭʹ��ѧ����Ϣ����ϵͳ----------" << endl << endl
		<< "     *    [1]��¼                     *     " << endl
		<< "     *    [0]�˳�                     *     " << endl << endl
		<< "********************************************" << endl << endl;
	int select;
	bool wrong_selection_flag = false;
	do
	{
		cout << "��ѡ�����Ĳ�����0-1����";
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
	cout << "======>>     �û���¼     <<======" << endl << endl;
	bool login_failed_flag = false;
	do
	{
		cout << "�������û�����";
		std::string username;
		cin >> username;
		cout << "���������룺";
		std::string password;
		cin >> password;
		switch (username[0])//UNDONE
		{
		case 'S':
		{
			login_failed_flag = false;
			if (SIM->login_decision(username, password))
			{
				cout << "��¼�ɹ���" << endl;
				administrator_interface();
			}
			else
			{
				login_failed((int)error_code_Type::Wrong_user_name_or_password, login_failed_flag);
			}
			break;
		}
		case 'T':
		{
			login_failed_flag = false;
			if (TIM->login_decision(username, password))
			{
				cout << "��¼�ɹ���" << endl;
				teacher_interface();
			}
			else
			{
				login_failed((int)error_code_Type::Wrong_user_name_or_password, login_failed_flag);
			}
			break;
		}
		case 'a':
		{
			login_failed_flag = false;
			if (AIM->login_decision(username, password))
			{
				cout << "��¼�ɹ���" << endl;
				administrator_interface();
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

void user_interface::administrator_interface()
{
	using std::cin, std::cout, std::endl;
	cout << endl
		<< "��ã�����Ա��" << AIM->return_currently_logged_in_administrator().return_username() << endl << endl;
	system("pause");
	do
	{
		cout << endl;
		cout << "********************************************" << endl
			<< "======>>       ����Ա�������       <<======" << endl
			<< endl
			<< "      *      [1]��ӹ���Ա           *      " << endl
			<< "      *      [2]��ӽ�ʦ             *      " << endl
			<< "      *      [3]���ѧ��             *      " << endl
			<< "      *      [4]�޸�����             *      " << endl
			<< "      *      [5]�¹��ܻ�������       *      " << endl
			<< "      *      [0]�˳�                 *      " << endl
			<< endl
			<< "********************************************" << endl << endl;

		bool wrong_selection_flag = false;
		int select;
		do//UNDONE
		{
			cout << "��ѡ�����Ĳ�����0-5����";
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
				break;
			}
			default:
			{
				wrong_selection((int)error_code_Type::Subscript_out_of_bounds, wrong_selection_flag);
				break;
			}
			}
		} while (wrong_selection_flag);
	} while (true);
}

void user_interface::teacher_interface()//TODO
{
	using std::cin, std::cout, std::endl;
	cout << endl
		<< "��ã���ʦ��" << AIM->return_currently_logged_in_administrator().return_username() << endl << endl;
	system("pause");
	cout << endl;
	cout << "********************************************" << endl
		<< "======>>       ��ʦ�������       <<======" << endl;
	cout << endl
		<< "      *      [1]ѧ����ѯ             *      " << endl
		<< "      *      [2]��������ѧ��         *      " << endl
		<< "      *      [3]�����Ͽοα�         *      " << endl
		<< "      *      [4]��������α�         *      " << endl
		<< "      *      [5]�޸�����             *      " << endl
		<< "      *      [6]�޸��ǳ�             *      " << endl
		<< "      *      [7]�¹��ܻ�������       *      " << endl
		<< "      *      [0]�˳�                 *      " << endl << endl
		<< "********************************************" << endl << endl;

	bool wrong_selection_flag = false;
	int select;
	do
	{
		cout << "��ѡ�����Ĳ�����0-7����";
		cin >> select;
		switch (select)
		{
		case 0:
		{
			wrong_selection_flag = false;
			return;
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

void user_interface::student_interface()//TODO
{
	using std::cin, std::cout, std::endl;
	cout << endl
		<< "��ã�ѧ����" << AIM->return_currently_logged_in_administrator().return_username() << endl << endl;
	system("pause");
	cout << endl;
	cout << "********************************************" << endl
		<< "======>>       ѧ���������       <<======" << endl;
	cout << endl
		<< "      *      [1]�ɼ���ѯ             *      " << endl
		<< "      *      [2]�����α�             *      " << endl
		<< "      *      [3]�޸�����             *      " << endl
		<< "      *      [4]�޸��ǳ�             *      " << endl
		<< "      *      [5]�¹��ܻ�������       *      " << endl
		<< "      *      [0]�˳�                 *      " << endl << endl
		<< "********************************************" << endl << endl;

	bool wrong_selection_flag = false;
	int select;
	do
	{
		cout << "��ѡ�����Ĳ�����0-5����";
		cin >> select;
		switch (select)
		{
		case 0:
		{
			wrong_selection_flag = false;
			return;
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

void user_interface::add_manager()
{
	using std::cin, std::cout, std::endl;
	administrator* admin = new administrator;
	cout << endl
		<< "======>>       ��ӹ���Ա       <<======" << endl << endl
		<< "�����·�����Ҫ��ӵ���Ϣ" << endl;

	std::string username;
	bool incorrect_username_format_flag = false;
	bool stop_add_flag = false;
	do
	{
		cout << "�������û���������Ա�û�����������ĸ a ��ͷ����";
		cin >> username;
		if (username[0] != 'a')
		{
			incorrect_username_format_flag = false;
			stop_add_flag = add_information_failed((int)error_code_Type::Incorrect_username_format, incorrect_username_format_flag);
		}
		else
		{
			admin->change_username(std::move(username));
			incorrect_username_format_flag = false;
		}
	} while (incorrect_username_format_flag);
	if (stop_add_flag)
	{
		delete admin;
		return;
	}
	stop_add_flag = false;
	bool inconsistent_passwords_flag = false;
	do
	{
		cout << "���������룺";
		std::string password1, password2;
		cin >> password1;
		cout << "���ظ����룺";
		cin >> password2;
		if (password1 != password2)
		{
			inconsistent_passwords_flag = false;
			stop_add_flag = add_information_failed((int)error_code_Type::The_two_passwords_are_inconsistent, inconsistent_passwords_flag);
		}
		else
		{
			admin->change_password(std::move(password1));
			inconsistent_passwords_flag = false;
		}
	} while (inconsistent_passwords_flag);
	if (stop_add_flag)
	{
		delete admin;
		return;
	}
	cout << "��ӳɹ���" << endl;
	AIM->add_manager(*admin);
	delete admin;
}

void user_interface::add_student()
{
	//TODO
}

void user_interface::add_teacher()
{
	//TODO
}
