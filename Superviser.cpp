#include "Superviser.h"


Case::Case(std::string_view anunt, bool stare) 
	      : anunt(anunt), stare(stare)
{
}

Superviser::~Superviser()
{
	for (size_t i{}; i < indicatii.size(); i++)
	{
		delete indicatii.at(i); 
	}
}

void Superviser::addCase(std::string_view anunt, bool stare)
{
	indicatii.push_back(generareCazuri(anunt, stare));
}

void Superviser::eraseCase(size_t index)
{
	if (index >= indicatii.size())
		return;

	indicatii.erase(indicatii.begin() + index); 
}

void Superviser::setStatus(bool status, size_t index)
{
	indicatii.at(index)->stare = status;
}

Case* Superviser::generareCazuri(std::string_view anunt, bool stare)
{
	return new Case(anunt, stare);
}

void Superviser::verificareStare(const Superviser* object)
{
	for (size_t i{}; i < object->indicatii.size(); i++)
	{
		if (object->indicatii.at(i)->stare)
		{
			std::cout << "\033[31m \t" << object->indicatii.at(i)->anunt << "\033[0m" << std::endl;
			object->indicatii.at(i)->stare = false;
		}
	}
}


