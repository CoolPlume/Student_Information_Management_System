#pragma once
#include "course.h"
#include <array>

class course_information_management
{
private:
	std::array <course, 11> course_list;
	int total_score;
protected:

public:
	course_information_management();
	int return_total_score();
	void change_the_selection_status(int, bool);
};

