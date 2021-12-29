#pragma once
#include <iostream>
#include <cstdlib>

enum error_code_Type
{
	Open_failed = 1,
	Illegal_file = 2
};

void initialization_failed(int);
void save_failed(int);