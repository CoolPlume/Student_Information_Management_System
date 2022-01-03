#pragma once
#include <iostream>
#include <cstdlib>

enum class error_code_Type
{
	Open_failed = 1,
	Illegal_file = 2,
	Subscript_out_of_bounds = 3,
	User_type_error = 4,
	Wrong_user_name_or_password = 5,
	The_two_passwords_are_inconsistent = 6,
	Incorrect_username_format = 7
};

[[noreturn]] void initialization_failed(int);
[[noreturn]] void save_failed(int);
[[noreturn]] void wrong_selection(int, bool&);
[[noreturn]] void login_failed(int, bool&);
bool add_information_failed(int, bool&);