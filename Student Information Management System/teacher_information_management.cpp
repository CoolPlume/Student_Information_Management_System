#pragma once
#include "teacher_information_management.h"

std::vector <std::string> teacher_storage_field_description =
{
	" ",
	"Username:",
	"Password:",
	"Gender:",
	"END"
};

enum teacher_storage_field_Type
{
	Space = 0,
	Username = 1,
	Password = 2,
	Gender = 3,
	END = 4
};

std::map <std::string, int> teacher_storage_field_Map
{
	{" ",0},
	{"Username:",1},
	{"Password:",2},
	{"Gender:",3},
	{"END",4}
};

teacher_information_management::teacher_information_management()
{
	std::ofstream create_local_file("teacher_list.txt", std::ios::app);
	if (create_local_file.is_open())
	{

	}
	else
	{
		initialization_failed((int)error_code_Type::Open_failed);
	}
	create_local_file.flush();
	create_local_file.close();

	std::ifstream read_local_date("teacher_list.txt", std::ios::in | std::ios::_Nocreate);
	if (read_local_date.is_open())
	{
		while (read_local_date.peek() != EOF)
		{
			std::string* judge;
			judge = new std::string;
			teacher* tea;
			tea = new teacher;
			bool read_end = false;
			do
			{
				read_local_date >> *judge;
				switch (teacher_storage_field_Map[*judge])
				{
				case Username:
				{
					read_local_date >> *judge;
					tea->change_username(*judge);
					break;
				}
				case Password:
				{
					read_local_date >> *judge;
					tea->change_password(*judge);
					break;
				}
				case Gender:
				{
					read_local_date >> *judge;
					tea->change_gender(std::stoi(*judge));
					break;
				}
				case END:
				{
					teacher_list.push_front(*tea);
					break;
				}
				default:
				{
					if (read_local_date.peek() == EOF)
						read_end = true;
					break;
				}
				}
			} while (*judge != "END" && read_end == false);
			delete judge;
			delete tea;
		}
	}
	else
	{
		initialization_failed((int)error_code_Type::Open_failed);
	}
	read_local_date.close();
}

teacher_information_management::~teacher_information_management()
{

}
