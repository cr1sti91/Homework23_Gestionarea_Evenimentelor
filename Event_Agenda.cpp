#include "Event_Agenda.h"


Date::Date(unsigned an, unsigned zi, std::string_view luna) : an(an), zi(zi), luna(luna)
{
}

std::ostream& operator<<(std::ostream& out, const Date event)
{
	out << event.zi << " " << event.luna << " " << event.an;
	return out;
}

/////////////////////////////////////////////////////////////////////
//Implementari pentru metodele clasei 'Event'
Event::Event(std::string_view nume, std::string_view descriere, std::string_view location, 
		     unsigned an, unsigned zi, std::string_view luna)
	        : eventName(nume), eventDescription(descriere), eventLocation(location), 
			  eventDate(an, zi, luna)
{
}

const std::string Event::get_eventName() const
{
	return this->eventName; 
}

const std::string Event::get_eventDescription() const
{
	return this->eventDescription; 
}

const std::string Event::get_eventLocation() const 
{
	return this->eventLocation;
}

const Date Event::get_eventDate() const
{
	return this->eventDate;
}

void Event::setEventName(std::string_view newName)
{
	this->eventName = newName; 
}

void Event::setEventDescription(std::string_view newDescription)
{
	this->eventDescription = newDescription; 
}

void Event::setEventLocation(std::string_view location)
{
	this->eventLocation = location;
}

void Event::setEventDate(unsigned an, unsigned zi, std::string_view luna)
{
	this->eventDate.an = an;
	this->eventDate.zi = zi;
	this->eventDate.luna = luna;
}


//Functie friend pentru afisare unui obiect de tip Event direct cu std::cout
std::ostream& operator<<(std::ostream& out, const Event* event)
{
	out << "\tNume eveniment:      " << event->eventName << std::endl
		<< "\tLocatie eveniment:   " << event->eventLocation << std::endl
		<< "\tData eveniment:      " << event->eventDate << std::endl
		<< "\tDescriere eveniment: " << event->eventDescription << std::endl;

	return out; 
}




///////////////////////////////////////////////////////////////////////
//Implementari pentru clasa Agenda
Agenda::~Agenda()
{
	for (size_t i{}; i < agenda.size(); i++)
	{
		delete agenda.at(i); 
	}
}

Event* Agenda::generareEvent(std::string_view nume, std::string_view descriere, 
							 std::string_view location, unsigned an, unsigned zi, std::string_view luna)
{
	return new Event(nume, descriere, location, an, zi, luna); 
}

Event& Agenda::get_event(size_t index)
{
	if (index < agenda.size())
		return *(agenda.at(index));

	std::cerr << RED << "\tIndex incorect!" << RESET << std::endl;
	std::cout << "index : " << index << std::endl;
	std::cout << "agenda.size() : " << agenda.size() << std::endl;
	assert(index < agenda.size());
}

size_t Agenda::get_size()
{
	return agenda.size();
}

void Agenda::printEvents()
{
	if (agenda.size() > 0)
	{
		for (size_t i{}; i < agenda.size(); i++)
		{
			std::cout << BLUE << "\tEveniment [" << i + 1 << "] : " << RESET << std::endl;
			std::cout << agenda.at(i) << std::endl;
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << GREEN << "\tAgenda nu contine evenimente!" << RESET << std::endl;
		std::cout << std::endl;
	}
	
}

void Agenda::addEvent(std::string_view nume, std::string_view descriere, 
					  std::string_view location, unsigned an, unsigned zi, std::string_view luna)
{
	agenda.push_back(generareEvent(nume, descriere, location, an, zi, luna)); 
}

void Agenda::eraseEvent(size_t index)
{
	if (index < agenda.size())
		agenda.erase(agenda.begin() + index);
	else
		std::cerr << RED << "\tIndex incorect!" << RESET << std::endl;
}

void Agenda::clear()
{
	if (agenda.size() > 0)
	{
		agenda.clear();
	}
	else 
	{
		std::cerr << RED << "\tAgenda nu contine evenimente!" << RESET << std::endl;
		std::cout << std::endl;
	}

}


