#include "student.h"

student::student()
{
	score = NULL;
}

student::~student()
{

}

student::student(const student& stu) :user(stu)
{
	this->score = stu.score;
}
