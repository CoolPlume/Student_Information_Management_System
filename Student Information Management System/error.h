#pragma once
#include <iostream>
#include <cstdlib>

enum initialization_failed_Type
{
	Open_failed = 1,
	Illegal_file = 2
};

void initialization_failed(int);