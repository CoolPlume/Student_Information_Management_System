#pragma once
#include <iostream>
#include <cstdlib>

enum class error_code_Type
{
	Open_failed = 1,
	Illegal_file = 2,
	Subscript_out_of_bounds = 3,
	User_type_error = 4,
	Wrong_user_name_or_password = 5
};

void initialization_failed(int);
void save_failed(int);
void wrong_selection(int, bool&);
void login_failed(int, bool&);