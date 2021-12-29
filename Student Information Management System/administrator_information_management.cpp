#pragma once
#include "administrator_information_management.h"

std::vector <std::string> administrator_storage_field_description =
{
	" ",
	"Username:",
	"Password:",
	"Super_administrator:",
	"END"
};

enum class administrator_storage_field_Type
{
	Space = 0,
	Username = 1,
	Password = 2,
	Super_administrator = 3,
	END = 4
};

std::map <std::string, int> administrator_storage_field_Map
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
				create_local_file << administrator_storage_field_description[(int)administrator_storage_field_Type::Username] << administrator_storage_field_description[(int)administrator_storage_field_Type::Space] << super_administrator->return_username() << administrator_storage_field_description[(int)administrator_storage_field_Type::Space]
					<< administrator_storage_field_description[(int)administrator_storage_field_Type::Password] << administrator_storage_field_description[(int)administrator_storage_field_Type::Space] << super_administrator->return_password() << administrator_storage_field_description[(int)administrator_storage_field_Type::Space]
					<< administrator_storage_field_description[(int)administrator_storage_field_Type::Super_administrator] << administrator_storage_field_description[(int)administrator_storage_field_Type::Space] << super_administrator->return_super_administrator() << administrator_storage_field_description[(int)administrator_storage_field_Type::Space]
					<< administrator_storage_field_description[(int)administrator_storage_field_Type::END] << std::endl;
			}
			else if (*judge == "admin")
			{

			}
			else
			{
				initialization_failed((int)error_code_Type::Illegal_file);
			}
			delete judge;
		}
		else
		{
			initialization_failed((int)error_code_Type::Open_failed);
		}
		whether_the_local_file_was_created_for_the_first_time.close();
	}
	else
	{
		initialization_failed((int)error_code_Type::Open_failed);
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
				switch (administrator_storage_field_Map[*judge])
				{
				case (int)administrator_storage_field_Type::Username:
				{
					read_local_date >> *judge;
					admin->change_username(*judge);
					break;
				}
				case (int)administrator_storage_field_Type::Password:
				{
					read_local_date >> *judge;
					admin->change_password(*judge);
					break;
				}
				case (int)administrator_storage_field_Type::Super_administrator:
				{
					read_local_date >> *judge;
					admin->change_super_administrator(std::stoi(*judge));
					break;
				}
				case (int)administrator_storage_field_Type::END:
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
		initialization_failed((int)error_code_Type::Open_failed);
	}
	read_local_date.close();
}

administrator_information_management::~administrator_information_management()
{
	std::ofstream write_local_data("administrator_list.txt", std::ios::out | std::ios::trunc | std::ios::_Nocreate);
	if (write_local_data.is_open())
	{
		for (const auto& i : administrator_list)
		{
			administrator* admin = new administrator(i);
			write_local_data << administrator_storage_field_description[(int)administrator_storage_field_Type::Username] << administrator_storage_field_description[(int)administrator_storage_field_Type::Space] << admin->return_username() << administrator_storage_field_description[(int)administrator_storage_field_Type::Space]
				<< administrator_storage_field_description[(int)administrator_storage_field_Type::Password] << administrator_storage_field_description[(int)administrator_storage_field_Type::Space] << admin->return_password() << administrator_storage_field_description[(int)administrator_storage_field_Type::Space]
				<< administrator_storage_field_description[(int)administrator_storage_field_Type::Super_administrator] << administrator_storage_field_description[(int)administrator_storage_field_Type::Space] << admin->return_super_administrator() << administrator_storage_field_description[(int)administrator_storage_field_Type::Space]
				<< administrator_storage_field_description[(int)administrator_storage_field_Type::END] << std::endl;
			delete admin;
		}
	}
	else
	{
		save_failed((int)error_code_Type::Open_failed);
	}
	write_local_data.flush();
	write_local_data.close();
}
