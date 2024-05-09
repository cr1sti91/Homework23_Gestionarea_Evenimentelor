#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <cassert>
#include <conio.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m" 

struct Date
{
	unsigned an{};
	unsigned zi{};
	std::string luna{};

	Date(unsigned an, unsigned zi, std::string_view luna); 

	friend std::ostream& operator<<(std::ostream& out, const Date event);
};

class Event
{
private: 
	std::string eventName = ""; 
	std::string eventDescription = "";
	std::string eventLocation = ""; 
	Date eventDate; 

public: 
	//Constructori si destructor
	Event() = default; 
	Event(std::string_view nume, std::string_view descriere, 
		  std::string_view location, unsigned an, unsigned zi, std::string_view luna); 
	~Event() = default;

	//Getters
	const std::string get_eventName() const;
	const std::string get_eventDescription() const;
	const std::string get_eventLocation() const;
	const Date get_eventDate() const;


	//Setters
	void setEventName(std::string_view);
	void setEventDescription(std::string_view);
	void setEventLocation(std::string_view);
	void setEventDate(unsigned, unsigned, std::string_view);

	//Functii
	friend std::ostream& operator<<(std::ostream& out, const Event* event); 
};


class Agenda
{
private: 
	std::vector<Event*> agenda; 

public: 
	//Constructor si destructor
	Agenda() = default; 
	~Agenda(); 


	Event* generareEvent(std::string_view nume, std::string_view descriere,
						 std::string_view location, unsigned an, unsigned zi, std::string_view luna);

	//Getter that works as setter (returneaza o referinta)
	Event& get_event(size_t index); 


	size_t get_size(); 

	//Afisarea tuturor evenimentelor din agenda
	void printEvents(); 

	//Setters
	void addEvent(std::string_view nume, std::string_view descriere,
				  std::string_view location, unsigned an, unsigned zi, std::string_view luna);
	void eraseEvent(size_t index); 
	void clear(); 
};


