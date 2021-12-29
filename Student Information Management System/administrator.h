#pragma once
#include "person.h"
class administrator :public person
{
private:
	bool super_administrator;
protected:

public:
	administrator();
	virtual ~administrator();
	administrator(const administrator&);
};