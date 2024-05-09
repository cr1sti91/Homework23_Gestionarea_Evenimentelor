#pragma once
#include <chrono>
#include <string>
#include <iostream>




class TimePoint
{
private:
	//Variabile membru
	unsigned an{};
	unsigned zi{};
	std::string luna{};
	std::chrono::time_point<std::chrono::system_clock> momentNastere{};

public:
	//Constructori
	TimePoint() = default;
	TimePoint(const unsigned& an, const unsigned& zi, const std::string& luna);

	//Metode
	const std::chrono::duration<double> calculVarsta() const;

	static bool esteAnBisect(int an);
	static unsigned luna_to_num(const std::string& luna);

	const unsigned get_an() const;
	const unsigned get_zi() const;
	const unsigned get_luna() const;

	static void afisareTimpScurs(const TimePoint&); 
};

