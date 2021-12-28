#pragma once
#include "person.h"
#include "user.h"

class student :public user
{
private:
	int score;

protected:

public:
	student();
	virtual ~student();
	student(const student&);
	
};