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

enum class teacher_storage_field_Type
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
				case (int)teacher_storage_field_Type::Username:
				{
					read_local_date >> *judge;
					tea->change_username(*judge);
					break;
				}
				case (int)teacher_storage_field_Type::Password:
				{
					read_local_date >> *judge;
					tea->change_password(*judge);
					break;
				}
				case (int)teacher_storage_field_Type::Gender:
				{
					read_local_date >> *judge;
					tea->change_gender(std::stoi(*judge));
					break;
				}
				case (int)teacher_storage_field_Type::END:
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
	std::ofstream write_local_data("teacher_list.txt", std::ios::out | std::ios::trunc | std::ios::_Nocreate);
	if (write_local_data.is_open())
	{
		for (const auto& i : teacher_list)
		{
			teacher* tea = new teacher(i);
			write_local_data << teacher_storage_field_description[(int)teacher_storage_field_Type::Username] << teacher_storage_field_description[(int)teacher_storage_field_Type::Space] << tea->return_username() << teacher_storage_field_description[(int)teacher_storage_field_Type::Space]
				<< teacher_storage_field_description[(int)teacher_storage_field_Type::Password] << teacher_storage_field_description[(int)teacher_storage_field_Type::Space] << tea->return_password() << teacher_storage_field_description[(int)teacher_storage_field_Type::Space]
				<< teacher_storage_field_description[(int)teacher_storage_field_Type::Gender] << teacher_storage_field_description[(int)teacher_storage_field_Type::Space] << tea->return_gender() << teacher_storage_field_description[(int)teacher_storage_field_Type::Space]
				<< teacher_storage_field_description[(int)teacher_storage_field_Type::END] << std::endl;
			delete tea;
		}
	}
	else
	{
		save_failed((int)error_code_Type::Open_failed);
	}
	write_local_data.flush();
	write_local_data.close();
}
