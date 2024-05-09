#include "Functii_auxiliare.h"
#include "Superviser.h"
#include "TimePoint.h"
    
extern Superviser* watcher;

void adaugareEveniment(Agenda* agenda)
{
    std::string nume, locatie, descriere;
    unsigned an{};
    unsigned zi{};
    std::string luna{};

    std::cout << "\tIntrodu numele evenimentului: ";
    std::getline(std::cin, nume);
    std::cout << "\tIntrodu locatia evenimentului: ";
    std::getline(std::cin, locatie);

    std::cout << "\tIntrodu ziua evenimentului (cifre): ";
    zi = verificareInput(); 

    std::cout << "\tIntrodu luna evenimentului (litere): ";
    std::cin >> luna; 

    std::cout << "\tIntrodu anul evenimentului (cifre): ";
    an = verificareInput(); 
    std::cin.ignore(); 

    std::cout << "\tIntrodu descrierea evenimentului: ";
    std::getline(std::cin, descriere);

    agenda->addEvent(nume, descriere, locatie, an, zi, luna);
}

void eliminareEveniment(Agenda* agenda)
{
    size_t index;
    std::cout << "\tIntrodu indexul evenimentului ce va fi eliminat: ";
    index = verificareInput(); 
    std::cin.ignore(); 

    if (index - 1 >= agenda->get_size())
    {
        watcher->setStatus(true, static_cast<size_t>(Exceptii::eventInex));
        return;
    }

    agenda->eraseEvent(index - 1);
}

void curatireAgenda(Agenda* agenda)
{
    if (agenda->get_size() == 0)
    {
        watcher->setStatus(true, static_cast<size_t>(Exceptii::agendaPustie));
        return;
    }
        
    agenda->clear(); 
}



static void modificareEvent(Event& event)
{
    bool final_interior = false;

    while (!final_interior)
    {
        system("CLS"); 
        std::cout << BLUE << "\tModificarea evenimentului: " << RESET << std::endl;
        std::cout << &event << std::endl;

        Superviser::verificareStare(watcher);

        std::cout << YELLOW << "\tMeniu modificare event" << RESET << std::endl;
        std::cout << Optiuni_modif_event << std::endl;

        char optiune = _getch();

        switch (optiune)
        {
        case '1':
        {
            std::string nume;
            std::cout << "\tIntrodu numele nou al evenimentului: ";
            std::getline(std::cin, nume);

            event.setEventName(nume);

        } break;

        case '2':
        {
            std::string locatie;
            std::cout << "\tIntrodu locatie nou al locatie: ";
            std::getline(std::cin, locatie);

            event.setEventLocation(locatie);

        } break;

        case '3':
        {
            unsigned an{};
            unsigned zi{};
            std::string luna{};
            std::cout << "\tIntrodu ziua evenimentului (cifre): ";
            zi = verificareInput();

            std::cout << "\tIntrodu luna evenimentului (litere): ";
            std::cin >> luna;

            std::cout << "\tIntrodu anul evenimentului (cifre): ";
            an = verificareInput();
            std::cin.ignore();

            event.setEventDate(an, zi, luna);

        } break;

        case '4':
        {
            std::string descriere;
            std::cout << "\tIntrodu numele nou al descriere: ";
            std::getline(std::cin, descriere);

            event.setEventDescription(descriere);

        } break;

        case '5':
        {
            final_interior = true;

        } break;

        default:
            watcher->setStatus(true, static_cast<size_t>(Exceptii::optiuneIncor));
            break;
        }
    }
}


static void afisareTimpScurs(const Event& event)
{
    //Data evenimentului trebuie sa fie sub forma 'zi luna an'. 
    //De exemplu '09 mai 2024'

    TimePoint eveniment(event.get_eventDate().an, event.get_eventDate().zi, event.get_eventDate().luna); 

    TimePoint::afisareTimpScurs(eveniment); 
    
}


void selectareEvent(Agenda* agenda)
{
    size_t index; 
    std::cout << "\tCe eveniment doriti sa selectati: "; 
    index = verificareInput(); 
    std::cin.ignore();

    if (index - 1 >= agenda->get_size())
    {
        watcher->setStatus(true, static_cast<size_t>(Exceptii::eventInex)); 
        return; 
    }

    bool final = false;
    bool timp_scurs_chemare = false; 

    while (!final)
    {
        system("CLS"); 
        //Functia 'operator<<' primeste pointeri catre eventuri
        std::cout << BLUE << "\tEveniment[" << index << "] selectat: " << RESET << std::endl;
        std::cout << &(agenda->get_event(index - 1)) << std::endl;

        if (timp_scurs_chemare)
        {
            afisareTimpScurs(agenda->get_event(index - 1));
            timp_scurs_chemare = false;
        }


        Superviser::verificareStare(watcher); 

        std::cout << YELLOW << "\tMeniu selectare event" << RESET << std::endl;
        std::cout << Optiuni_event << std::endl;
        char optiune = _getch(); 

        switch (optiune)
        {
        case '1': 
        {
            modificareEvent(agenda->get_event(index - 1)); 

        } break;

        case '2':
        {
            std::cout << "\tEvenimentul " << agenda->get_event(index - 1).get_eventName()
                      << " a fost eliminat." << std::endl;
            agenda->eraseEvent(index - 1);
            watcher->setStatus(true, static_cast<size_t>(Exceptii::elemEliminat)); 
            return;

        } break;

        case '3':
        {
            timp_scurs_chemare = true;

        } break;

        case '4':
        {
            final = true;

        } break;

        default:
            watcher->setStatus(true, static_cast<size_t>(Exceptii::optiuneIncor));
            break;
        }


    }
}




size_t verificareInput()
{
    size_t index{};

    while (!(std::cin >> index))
    {
        //Daca sunt introduse alte caracter care nu se potrivesc pentru variabilele de intrare, fluxul cin 
        //cade in stare de eroare.
        std::cin.clear(); //Curata starea de eroare
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Toate caracterele din buffer
        //sunt sterse pana la ultimul newline ultimul newline
        std::cout << RED << "\tAi introdus caractere gresite! Incerca din nou: " << RESET;
    }

    return index;
}