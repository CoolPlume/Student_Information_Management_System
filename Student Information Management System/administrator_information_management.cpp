#pragma once
#include "administrator_information_management.h"

std::vector <std::string> storage_field_description =
{
	" ",
	"Username:",
	"Password:",
	"Super_administrator:",
	"END"
};

enum storage_field_Type
{
	Space = 0,
	Username = 1,
	Password = 2,
	Super_administrator = 3,
	END = 4
};

std::map <std::string, int> storage_field_Map
{
	{" ",0},
	{"Username:",1},
	{"Password:",2},
	{"Super_administrator:",3},
	{"END",4}
};

administrator_information_management::administrator_information_management()
{
	std::ofstream create_local_file("administrator_list.txt", std::ios::app);
	if (create_local_file.is_open())
	{
		std::ifstream whether_the_local_file_was_created_for_the_first_time("administrator_list.txt", std::ios::in);
		if (whether_the_local_file_was_created_for_the_first_time.is_open())
		{
			std::string* judge;
			judge = new std::string;
			whether_the_local_file_was_created_for_the_first_time >> *judge >> *judge;
			if (judge -> empty())
			{
				administrator* super_administrator = new administrator("admin", "123456", true);
				create_local_file << storage_field_description[Username] << storage_field_description[Space] << super_administrator->return_username() << storage_field_description[Space]
					<< storage_field_description[Password] << storage_field_description[Space] << super_administrator->return_password() << storage_field_description[Space]
					<< storage_field_description[Super_administrator] << storage_field_description[Space] << super_administrator->return_super_administrator() << storage_field_description[Space]
					<< storage_field_description[END] << std::endl;
			}
			else if (*judge == "admin")
			{

			}
			else
			{
				initialization_failed(Illegal_file);
			}
			delete judge;
		}
		else
		{
			initialization_failed(Open_failed);
		}
	}
	else
	{
		initialization_failed(Open_failed);
	}
	create_local_file.flush();
	create_local_file.close();

	std::ifstream read_local_date("administrator_list.txt", std::ios::in | std::ios::_Nocreate);
	if (read_local_date.is_open())
	{
		while (read_local_date.peek() != EOF)
		{
			std::string* judge;
			judge = new std::string;
			administrator* admin;
			admin = new administrator;
			bool read_end = false;
			do
			{
				read_local_date >> *judge;
				switch (storage_field_Map[*judge])
				{
				case Username:
				{
					read_local_date >> *judge;
					admin->change_username(*judge);
					break;
				}
				case Password:
				{
					read_local_date >> *judge;
					admin->change_password(*judge);
					break;
				}
				case Super_administrator:
				{
					read_local_date >> *judge;
					admin->change_super_administrator(std::stoi(*judge));
					break;
				}
				case END:
				{
					administrator_list.push_front(*admin);
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
			delete admin;
		}
	}
	else
	{
		initialization_failed(Open_failed);
	}
	read_local_date.close();
}

administrator_information_management::~administrator_information_management()
{

}
