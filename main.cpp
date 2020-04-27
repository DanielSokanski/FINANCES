#include <iostream>
#include "YourBudget.h"
using namespace std;

int main()
{
    //FileWithUsers fileWithUsers("users.xml");

    YourBudget yourBudget;
    int loggedInUserId=0;
    char choise;
    while (true)
    {
        if (yourBudget.isUserLogedIn()==false)
        {
            choise = yourBudget.chooseOptionFromMainMenu();

            switch (choise)
            {
            case '1':
                yourBudget.registrationOfUser();
                break;

            case '2':
                //ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                //exit(0);
                break;
            case '3':
                yourBudget.showAllUsers();
                system("pause");
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;

            }
        }
        else
        {
            if (yourBudget.isUserLogedIn() == true)
            choise = yourBudget.chooseOptionFromUserMenu();
            switch (choise)
            {
            case '1':
                //ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                //ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                //ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0;
}

