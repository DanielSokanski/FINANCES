#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Incomes.h"
#include "Markup.h"
#include "XMLFile.h"
#include "IncomeManager.h"

class FileWithIncomes: public XMLFile
{
    const string FILE_NAME_WITH_INCOMES;
    int lastIncomeId;
    Incomes loadIncomesOfLoggedInUser();

public:
    FileWIthIncomes(string fileName) : XMLFile(fileName)
        {
        lastIncomeId = 0;
        );
    bool addIncomesToFile();
    int getIdOfLastIncome();
};

#endif
