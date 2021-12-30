#pragma once
#include "administrator.h"
#include <fstream>
#include "error.h"
#include <forward_list>
#include <vector>
#include <string>
#include <map>
#include <ios>

class administrator_information_management
{
private:
	std::forward_list <administrator> administrator_list;
	administrator currently_logged_in_administrator;
protected:

public:
	administrator_information_management();
	~administrator_information_management();
	bool add_manager(const administrator&);
};