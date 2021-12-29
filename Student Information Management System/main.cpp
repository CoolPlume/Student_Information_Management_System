#include <iostream>
#include "student.h"

int main()
{
	student stu1;
	person per;
	stu1.change("123");
	//std::cout << stu1.passw() << std::endl;
	student stu2;
	stu2 = stu1;
	//std::cout << stu2.passw() << std::endl;
	//std::cout << stu1.oouthout();
	//std::cout << stu2.oouthout();
}