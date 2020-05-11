#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include<iostream>
#include<vector>
#include<windows.h>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include"UserManager.h"
#include"FileWithUsers.h"
#include"FileWithIncomes.h"
#include"Incomes.h"
#include"User.h"
#include"XMLFile.h"

using namespace std;

class IncomeManager
{
    FileWithIncomes fileWithIncomes;
    const int LOGGED_IN_USER_ID;
    vector <Incomes>incomes;
    int loggedInUserId;
    void showIncomesData(Incomes income);
public:
    IncomeManager(string fileNameWithIncomes, int loggedInUserId) :
        fileWithIncomes(fileNameWithIncomes), LOGGED_IN_USER_ID (loggedInUserId)
        {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUser(LOGGED_IN_USER_ID);
        };
    Incomes enterNewIncome();
    void showAllIncomes();
    void addIncomes();
    float changeCommaToDotInAmount();
    float getIncomesFromCurrentMonth();
    float getIncomesFromPreviousMonth();
    float getIncomesFromCustomDate();
    bool checkIfDateIsCorrect();
    char getSign();
};


#endif
