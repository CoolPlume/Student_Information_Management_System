#pragma once
#include "administrator.h"
#include <fstream>
#include "error.h"
#include <list>
#include <vector>
#include <string>
#include <map>
#include <ios>

class administrator_information_management
{
private:
	std::list <administrator> administrator_list;
	administrator* currently_logged_in_administrator;
protected:

public:
	administrator_information_management();
	~administrator_information_management();
	bool add_manager(const administrator&);
	bool login_decision(const std::string&, const std::string&);
	administrator return_currently_logged_in_administrator()const;
	administrator* revise_currently_logged_in_administrator()const;
};