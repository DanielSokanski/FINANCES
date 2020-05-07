#ifndef FILEWITHEXPENCES_H
#define FILEWITHEXPENCES_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Incomes.h"
#include "Markup.h"
#include "XMLFile.h"
#include "eExpenceManager.h"

class FileWithExpences: public XMLFile
{
    const string FILE_NAME_WITH_INCOMES;
    int lastExpenceId;
    Expence loadExpenceOfLoggedInUser();

public:
    FileWithExpences(string fileName) : XMLFile(fileName)
        {
        lastExpenceId = 0;
        );
    bool addExpenceToFile();
    int getIdOfLastExpence();
};

#endif
