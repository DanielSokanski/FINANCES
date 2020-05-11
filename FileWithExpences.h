#ifndef FILEWITHEXPENCES_H
#define FILEWITHEXPENCES_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Incomes.h"
#include "Markup.h"
#include "XMLFile.h"
#include "ExpenceManager.h"

class FileWithExpences: public XMLFile
{
    const string FILE_NAME_WITH_INCOMES;
    int lastExpenceId;
    int loadUserId();
public:
    FileWithExpences(string fileName) : XMLFile(fileName)
        {
        lastExpenceId = 0;
        );
    bool addExpenceToFile(Expences expences);
    int getIdOfLastExpence();
    vector <Incomes> loadExpenceOfLoggedInUser();
    int changeToNumber(string date);
};

#endif
