#ifndef EXPENCEMANAGER_H
#define EXPENCEMANAGER_H

#include<iostream>
#include<vector>
#include<windows.h>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include"UserManager.h"
#include"FileWithUsers.h"
#include"FileWithExpences.h"
#include"Expences.h"
#include"User.h"
#include"XMLFile.h"
using namespace std;

class ExpenceManager
{
    int LOGGED_IN_USER_ID;
    vector <Expence>expences;
    FileWithExpence fileWithExpences;
    int loggerInUserId;
    void showExpenceData();
public:
    ExpenceManager(string fileNameWithExpences, int loggerInUserId) :
        fileWithExpences(fileNameWithExpences), LOGGED_IN_USER_ID (loggerInUserId)
        {
        expences = fileWithExpences.loadExpencesOfLoggedInUser(LOGGED_IN_USER_ID);
        };
    void showAllExpences();
    void addExpence();
    float changeCommaToDotInAmount();
    float getExpenceFromCurrentMonth();
    float getExpenceFromPreviousMonth();
    float getExpenceFromCustomDate();
    bool checkIfDateIsCorrect();
    char getSign();
};


#endif
