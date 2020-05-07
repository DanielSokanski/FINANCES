#ifndef YOURBUDGET_H
#define YOURBUDGET_H

#include<iostream>

#include "UserManager.h"
#include "IncomeManager.h"


using namespace std;

class YourBudget
{
    UserManager userManager;
    IncomeManager *incomeManager;
    const string FILE_NAME_WITH_INCOMES;
public:
    YourBudget
    (string FileNameWithUsers, string fileNameWithIncomes) :
    userManager(FileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes)
    {
    incomeManager = NULL;
    };
    ~YourBudget()
    {
        delete incomeManager;
        incomeManager = NULL;
    };
    bool isUserLogedIn();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void registrationOfUser();
    void showAllUsers();
    void loginOfUser();
};


#endif
