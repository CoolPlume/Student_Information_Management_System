#pragma once
#include "student_information_management.h"

student_information_management::student_information_management()
{
	std::ofstream read_local_data("student_list.txt", std::ios::app);
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

student_information_management::~student_information_management()
{
}
