#ifndef YOURBUDGET_H
#define YOURBUDGET_H

#include<iostream>

#include "UserManager.h"


using namespace std;

class YourBudget
{
    UserManager userManager;
    //AdresatManager *adresatManager;
    //const string NAZWA_PLIKU_Z_ADRESATAMI;
public:
    /*YourBudget
    (string NazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) :
    uzytkownikManadzer(NazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
    adresatManager = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatManager;
        adresatManager = NULL;
    };*/
    bool isUserLogedIn();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void registrationOfUser();
    void showAllUsers();
};


#endif
