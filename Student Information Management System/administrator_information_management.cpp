#pragma once
#include "administrator_information_management.h"

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
			whether_the_local_file_was_created_for_the_first_time >> *judge;
			if (judge -> empty())
			{
				create_local_file << "Username:admin Password:123456 Super_administrator:true" << std::endl;
			}
			else if (*judge == "Username:admin")
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
		while (!read_local_date.eof())
		{
			break;
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
