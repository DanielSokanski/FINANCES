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
    int LOGGED_IN_USER_ID;
    vector <Incomes>incomes;
    FileWithIncomes fileWithIncomes;
    int loggerInUserId;
    void showIncomesData();
public:
    IncomeManager(string fileNameWithIncomes, int loggerInUserId) :
        fileWithIncomes(fileNameWithIncomes), LOGGED_IN_USER_ID (loggerInUserId)
        {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUser(LOGGED_IN_USER_ID);
        };
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
