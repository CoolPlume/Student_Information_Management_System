#include "timer.h"

timer::timer()
{
	//TODO
}

timer::~timer()
{
}

timer::timer(const timer& timer)
{
	this -> Day = timer.Day;
	this -> Hour = timer.Hour;
	this -> Minute = timer.Minute;
	this -> Month = timer.Month;
	this -> Second = timer.Second;
	this -> Year = timer.Year;
}

void timer::record_the_current_time()
{
	//UNDONE
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::chrono::nanoseconds d = now.time_since_epoch();
	Hour = std::chrono::duration_cast<std::chrono::hours>(d);
}

std::chrono::hours timer::outhour()
{
	return Hour;
}
