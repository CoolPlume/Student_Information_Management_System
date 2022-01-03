#pragma once
#include "course.h"
#include <array>

class course_information_management
{
private:
	std::array <course, 11> course_list{};
	int total_score;
protected:

public:
	course_information_management();
	~course_information_management();
	int return_total_score();
	[[noreturn]] void change_the_selection_status(int, bool);
	[[nodiscard]] int return_course_results(int)const;
	[[nodiscard]] bool return_the_selection_status(int)const;
};

