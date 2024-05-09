//#include "Classes.h"
#include "Functii_auxiliare.h"
#include "Superviser.h"

//Variabila (pointer) externa
Superviser* watcher = new Superviser;


int main()
{
    std::cout << YELLOW << "\tAGENDA DE EVENIMENTE" << RESET << std::endl;
    std::cout <<           "\t--------------------" << std::endl;

    std::cout << Optiuni_intrare << std::endl;

    char optiune = _getch(); //Citeste un caracter fara al afisa

    switch (optiune)
    {
    case '1':
    {
        Agenda* agenda = new Agenda();

        bool finish = false; 
        bool optiuneIncorecta = false;

        
        //Exceptii ce pot aparea cat ruleaza bucla 'while(!finish)'
        //Este putin de hardcoding, fiindca ordinea in care sunt adaugate cazurile este 
        //dependenta de ordinea in care sunt aranjate elementele in enum clasa Exceptii
        watcher->addCase("Optiune incorecta", false);
        watcher->addCase("Event inexistent", false);
        watcher->addCase("Agenda pustie", false);
        watcher->addCase("Eveniment eliminat in meniul selectare event", false);

        while (!finish)
        {
            system("CLS"); 
            agenda->printEvents(); 

            Superviser::verificareStare(watcher); 

            std::cout << YELLOW << "\tMeniu principal" << RESET << std::endl;
            std::cout << Optiuni_rulare << std::endl;

            optiune = _getch(); //De la tastatura sunt imediat citite caracterele fara butonul 'enter'


            switch (optiune)
            {
            case '1': 
            {
                adaugareEveniment(agenda); 

            } break;

            case '2': 
            {
                eliminareEveniment(agenda);

            } break;

            case '3': 
            {
                curatireAgenda(agenda);

            } break;

            case '4':
            {
                selectareEvent(agenda);

            } break;

            case '5': 
            {
                finish = true;

            } break;
           
            default:
                watcher->setStatus(true, static_cast<size_t>(Exceptii::optiuneIncor)); 
                break;
            }
        }

        delete agenda;
        break;
    }
    case '2':
    {
        std::cout << YELLOW << "\tO zi buna in continuare!" << RESET << std::endl;
        break;
    }
    default:
    {
        std::cout << RED << "Optiune incorecta!" << RESET << std::endl;
        delete watcher;
        return 0;
        break; 
    }
    }   

    std::cout << YELLOW << "\tO zi buna in continuare!" << RESET << std::endl;
    delete watcher;
    return 0;
}

