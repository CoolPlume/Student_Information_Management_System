#pragma once
#include "student_information_management.h"

std::vector <std::string> student_storage_field_description =
{
	" ",
	"Username:",
	"Password:",
	"Gender:",
	"END",
	"Actual_name:",
	"Nick_name:",
	"Chinese:",
	"Mathematics:",
	"Foreign_language:",
	"Politics:",
	"History:",
	"Geography:",
	"Physics:",
	"Chemical:",
	"Biology:",
	"Information_technology:",
	"Common_technology:",
};

enum class student_storage_field_Type
{
	Space = 0,
	Username = 1,
	Password = 2,
	Gender = 3,
	END = 4,
	Actual_name = 5,
	Nick_name = 6,
	Chinese = 7,
	Mathematics = 8,
	Foreign_language = 9,
	Politics = 10,
	History = 11,
	Geography = 12,
	Physics = 13,
	Chemical = 14,
	Biology = 15,
	Information_technology = 16,
	Common_technology = 17,
};

std::map <std::string, int> student_storage_field_Map
{
	{" ",0},
	{"Username:",1},
	{"Password:",2},
	{"Gender:",3},
	{"END",4},
	{"Actual_name:",5},
	{"Nick_name:",6},
	{"Chinese:",7},
	{"Mathematics:",8},
	{"Foreign_language:",9},
	{"Politics:",10},
	{"History:",11},
	{"Geography:",12},
	{"Physics:",13},
	{"Chemical:",14},
	{"Biology:",15},
	{"Information_technology:",16},
	{"Common_technology:",17},
};

enum class login_decision_return_code_Type
{
	login_failed = 0,
	login_successful = 1
};

student_information_management::student_information_management()
{
	std::ofstream create_local_file("student_list.txt", std::ios::app);
	if (create_local_file.is_open())
	{
		
	}
	else
	{
		initialization_failed(static_cast<int>(error_code_Type::Open_failed));
	}
	create_local_file.flush();
	create_local_file.close();

	std::ifstream read_local_date("student_list.txt", std::ios::in | std::ios::_Nocreate);
	if (read_local_date.is_open())
	{
		while (read_local_date.peek() != EOF)
		{
			std::string* judge;
			judge = new std::string;
			student* stu;
			stu = new student;
			bool read_end = false;
			do
			{
				read_local_date >> *judge;
				switch (student_storage_field_Map[*judge])
				{
				case static_cast<int>(student_storage_field_Type::Username):
				{
					read_local_date >> *judge;
					stu->change_username(*judge);
					break;
				}
				case static_cast<int>(student_storage_field_Type::Password):
				{
					read_local_date >> *judge;
					stu->change_password(*judge);
					break;
				}
				case static_cast<int>(student_storage_field_Type::Gender):
				{
					read_local_date >> *judge;
					stu->change_gender(std::stoi(*judge));
					break;
				}
				case static_cast<int>(student_storage_field_Type::Actual_name):
				{
					read_local_date >> *judge;
					stu->change_actual_name(*judge);
					break;
				}
				case static_cast<int>(student_storage_field_Type::Nick_name):
				{
					read_local_date >> *judge;
					stu->change_nick_name(*judge);
					break;
				}
				case static_cast<int>(student_storage_field_Type::END):
				{
					student_list.push_back(*stu);
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
			delete stu;
		}
	}
	else
	{
		initialization_failed(static_cast<int>(error_code_Type::Open_failed));
	}
	read_local_date.close();
}

student_information_management::~student_information_management()
{
	std::ofstream write_local_data("student_list.txt", std::ios::out | std::ios::trunc | std::ios::_Nocreate);
	if (write_local_data.is_open())
	{
		for (const auto& i : student_list)
		{
			const student* stu = new student(i);
			write_local_data << student_storage_field_description[static_cast<int>(student_storage_field_Type::Username)] << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)] << stu->return_username() << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)]
				<< student_storage_field_description[static_cast<int>(student_storage_field_Type::Password)] << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)] << stu->return_password() << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)]
				<< student_storage_field_description[static_cast<int>(student_storage_field_Type::Gender)] << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)] << stu->return_gender() << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)]
				<< student_storage_field_description[static_cast<int>(student_storage_field_Type::Actual_name)] << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)] << stu->return_actual_name() << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)]
				<< student_storage_field_description[static_cast<int>(student_storage_field_Type::Nick_name)] << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)] << stu->return_nick_name() << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)]
				<< student_storage_field_description[static_cast<int>(student_storage_field_Type::Chinese)] << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)] << stu->return_course_information_management().return_the_selection_status(static_cast<int>(course_Type::chinese)) << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)] << stu->return_course_information_management().return_course_results(static_cast<int>(course_Type::chinese)) << student_storage_field_description[static_cast<int>(student_storage_field_Type::Space)]
				<< student_storage_field_description[static_cast<int>(student_storage_field_Type::END)] << std::endl;
			delete stu;
		}
	}
	else
	{
		save_failed(static_cast<int>(error_code_Type::Open_failed));
	}
	write_local_data.flush();
	write_local_data.close();
}

bool student_information_management::login_decision(const std::string& username, const std::string& password)
{
	bool return_code = 0;
	auto i = student_list.begin();
	for (i; i != student_list.end(); ++i)
	{
		const student* stu = new student(*i);
		if ((stu->return_username() == username) && (stu->return_password() == password))
		{
			return_code = static_cast<int>(login_decision_return_code_Type::login_successful);
			currently_logged_in_student = &*i;
		}
		delete stu;
	}
	if ((return_code != static_cast<int>(login_decision_return_code_Type::login_successful)) && (i == student_list.end()))
	{
		return_code = static_cast<int>(login_decision_return_code_Type::login_failed);
	}
	return return_code;
}

[[nodiscard]] student student_information_management::return_currently_logged_in_student() const
{
	return *currently_logged_in_student;
}

[[noreturn]] void student_information_management::add_student(const student& stu)
{
	student_list.push_back(stu);
}

[[nodiscard]] size_t student_information_management::return_student_list_size() const
{
	return student_list.size();
}

[[nodiscard]] student* student_information_management::revise_currently_logged_in_student() const
{
	return currently_logged_in_student;
}

[[nodiscard]] student* student_information_management::find_student(const std::string& username) const
{
	student* stu = nullptr;
	for (const auto& i : student_list)
	{
		if (i.return_username() == username)
		{
			stu = const_cast<student*>(&i);
		}
	}
	return stu;
}
