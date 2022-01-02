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
				cout << "��¼�ɹ���" << endl;
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
				cout << "��¼�ɹ���" << endl;
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
		<< "��ã�����Ա��" << AIM->return_currently_logged_in_administrator().return_username() << endl << endl;
	system("pause");
	do//UNDONE �����ת
	{
		cout << endl;
		cout << "********************************************" << endl
			<< "======>>       ����Ա�������       <<======" << endl
			<< endl
			<< "      *      [1]��ӹ���Ա           *      " << endl
			<< "      *      [2]��ӽ�ʦ             *      " << endl
			<< "      *      [3]���ѧ��             *      " << endl
			<< "      *      [4]�޸�����             *      " << endl
			<< "      *      [5]�л���ʦ���         *      " << endl
			<< "      *      [6]�л�ѧ�����         *      " << endl
			<< "      *      [7]�¹��ܻ�������       *      " << endl
			<< "      *      [0]�˳�                 *      " << endl
			<< endl
			<< "********************************************" << endl << endl;

		bool wrong_selection_flag = false;
		int select;
		do//UNDONE
		{
			cout << "��ѡ�����Ĳ�����0-6����";
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
			<< "��ã���ʦ��" << TIM->return_currently_logged_in_teacher().return_nick_name() << endl << endl;
		system("pause");
	}

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
		case 5:
		{
			wrong_selection_flag = false;
			if (user_type != static_cast<int>(user_Type::teacher))
			{
				cout << "������ʹ�ý�ʦ�˻������д˲�����" << endl;
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
				cout << "������ʹ�ý�ʦ�˻������д˲�����" << endl;
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
			<< "��ã�ѧ����" << SIM->return_currently_logged_in_student().return_nick_name() << endl << endl;
		system("pause");
	}

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
		case 3:
		{
			wrong_selection_flag = false;
			if (user_type != static_cast<int>(user_Type::student))
			{
				cout << "������ʹ��ѧ���˻������д˲�����" << endl;
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
				cout << "������ʹ��ѧ���˻������д˲�����" << endl;
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
		<< "======>>       ��ӹ���Ա       <<======" << endl << endl
		<< "�����·�����Ҫ��ӵ���Ϣ" << endl;

	std::string username;
	bool incorrect_username_format_flag = false;
	bool stop_add_flag = false;
	do
	{
		do
		{
			cout << "�������û���������Ա�û�����������ĸ a ��ͷ����";
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
			cout << "���������룺";
			std::string password1, password2;
			cin >> password1;
			cout << "���ظ����룺";
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
		cout << "��ӳɹ���" << endl;
		AIM->add_manager(*admin);
	} while (false);
	delete admin;
}

void user_interface::add_student()
{
	using std::cin, std::cout, std::endl;
	student* stu = new student;
	cout << endl
		<< "======>>       ���ѧ��       <<======" << endl << endl
		<< "�����·�����Ҫ��ӵ���Ϣ" << endl;

	do
	{
		std::string actual_name;
		bool stop_add_flag = false;
		cout << "������ѧ��������";
		cin >> actual_name;
		stu->change_actual_name(actual_name);

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
			cout << "�������Ա�0���У�1��Ů����";
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

		cout << "��ӳɹ���" << endl;
		SIM->add_student(*stu);
	} while (false);
	delete stu;
}

void user_interface::add_teacher()
{
	using std::cin, std::cout, std::endl;
	teacher* tea = new teacher;
	cout << endl
		<< "======>>       ��ӽ�ʦ       <<======" << endl << endl
		<< "�����·�����Ҫ��ӵ���Ϣ" << endl;

	do
	{
		std::string actual_name;
		bool stop_add_flag = false;
		cout << "�������ʦ������";
		cin >> actual_name;
		tea->change_actual_name(actual_name);

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
			cout << "�������Ա�0���У�1��Ů����";
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

		cout << "��ӳɹ���" << endl;
		TIM->add_teacher(*tea);
	} while (false);
	delete tea;
}

void user_interface::change_password(int user_type)
{
	using std::cin, std::cout, std::endl;
	cout << endl
		<< "======>>       �޸�����       <<======" << endl << endl;
	do
	{
		bool stop_add_flag = false;
		bool inconsistent_passwords_flag = false;
		do
		{
			cout << "�������޸ĺ�����룺";
			std::string password1, password2;
			cin >> password1;
			cout << "���ظ����룺";
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
						cout << "��������Ա�������޸����룡" << endl;
					}
					else
					{
						AIM->revise_currently_logged_in_administrator()->change_password(password1);
						cout << "�޸ĳɹ���" << endl;
					}
					break;
				}
				case static_cast<int>(user_Type::teacher):
				{
					TIM->revise_currently_logged_in_teacher()->change_password(password1);
					cout << "�޸ĳɹ���" << endl;
					break;
				}
				case static_cast<int>(user_Type::student):
				{
					SIM->revise_currently_logged_in_student()->change_password(password1);
					cout << "�޸ĳɹ���" << endl;
					break;
				}
				}
				inconsistent_passwords_flag = false;
			}
		} while (inconsistent_passwords_flag);
		if (stop_add_flag)
		{
			cout << "ȡ���޸ģ�" << endl;
			break;
		}
	} while (false);
}

void user_interface::change_nick_name(int user_type)
{
	using std::cin, std::cout, std::endl;
	cout << endl
		<< "======>>       �޸��ǳ�       <<======" << endl << endl;

	std::string nick_name;
	cout << "�������޸ĺ���ǳƣ�";
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
