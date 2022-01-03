#include "course.h"

course::course()
{
	course_results = 0;
	is_select_subjects = false;
}

course::~course()
= default;

[[noreturn]] void course::change_the_selection_status(bool is_select_subjects)
{
	this->is_select_subjects = is_select_subjects;
}

[[nodiscard]] bool course::return_the_selection_status() const
{
	return is_select_subjects;
}

[[nodiscard]] int course::return_course_results() const
{
	return course_results;
}
