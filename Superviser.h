#pragma once
#include <string>
#include <iostream>
#include <vector>


//Pentru indicarea cazurilor in obiectul de tip 'Superviser'
enum class Exceptii
{
	optiuneIncor = 0, eventInex, agendaPustie, elemEliminat
};


struct Case
{	
	std::string anunt; 
	bool stare;

	Case(std::string_view, bool);
};

//O instanta a clasei date va putea duce cont de orice input problematic de la tastatura
class Superviser
{
private: 
	std::vector<Case*> indicatii; 

public: 
	Superviser() = default; 
	~Superviser(); 

	//Setters 
	void addCase(std::string_view, bool); 
	void eraseCase(size_t);
	void setStatus(bool, size_t); 
	

	//Metode 
	Case* generareCazuri(std::string_view, bool); 


	//Metode speciale
	static void verificareStare(const Superviser*);
};

