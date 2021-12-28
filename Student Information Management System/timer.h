#pragma once
#include <chrono>
#include <ctime>

class timer
{
private:
	std::chrono::hours Hour;
	std::chrono::minutes Minute;
	std::chrono::seconds Second;
	std::chrono::days Day;
	std::chrono::months Month;
	std::chrono::year Year;
protected:

public:
	timer();
	virtual ~timer();
	timer(const timer&);
	void record_the_current_time();
	std::chrono::hours outhour();
};