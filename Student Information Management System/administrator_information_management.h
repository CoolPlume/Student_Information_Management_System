#pragma once
#include "administrator.h"
#include <fstream>
#include "error.h"
#include <forward_list>

class administrator_information_management
{
private:
	std::forward_list <administrator> administrator_list;
protected:

public:
	administrator_information_management();
	~administrator_information_management();
};