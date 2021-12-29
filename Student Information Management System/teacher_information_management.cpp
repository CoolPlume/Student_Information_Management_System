#pragma once
#include "teacher_information_management.h"

teacher_information_management::teacher_information_management()
{
	std::ofstream read_local_data("teacher_list.txt", std::ios::app);
	if (read_local_data.is_open())
	{

	}
	else
	{
		initialization_failed(Open_failed);
	}
	read_local_data.flush();
	read_local_data.close();
}

teacher_information_management::~teacher_information_management()
{

}
