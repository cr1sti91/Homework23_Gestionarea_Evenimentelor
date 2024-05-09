#pragma once
#include "Event_Agenda.h"

const std::string Optiuni_intrare = { R"(
        1.Creare agenda
        2.Iesire din aplicatie
)" };

const std::string Optiuni_rulare = { R"(
        1.Adaugare eveniment
        2.Eliminare eveniment
        3.Eliminarea tuturor evenimentelor
        4.Selectare eveniment
        5.Iesire din aplicatie
)" };

const std::string Optiuni_event = { R"(
        1.Modificare eveniment
        2.Eliminare eveniment
        3.Afisare durata de timp scursa
        4.Iesire din optiunile evenimentului
)" };

const std::string Optiuni_modif_event = { R"(
        1.Modificare nume
        2.Modificare locatie
        3.Modificare data
        4.Modificare descriere
        5.Iesire din optiuni de modificare
)" };

void adaugareEveniment(Agenda* agenda);
void eliminareEveniment(Agenda* agenda);
void curatireAgenda(Agenda* agenda);
void selectareEvent(Agenda* agenda); 

//Daca in stream-ul std::cin sunt date caractere incorecte manuim exceptia data
size_t verificareInput(); 