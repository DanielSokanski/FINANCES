#include "FileWithIncomes.h"

vector <Incomes> FileWithIncomes::loadIncomesOfLoggedInUser()
{
    int date;
    Incomes income;
    vector <Incomes> incomes;
    CMarkup xml;
    xml.Load( "incomes.xml" );
    xml.FindElem( "Incomes" );
    xml.IntoElem();
    while(xml.FindElem( "Income" ))
    {
    xml.IntoElem();
    xml.FindElem("userId");
    int USERID = atoi(MCD_2PCSZ(xml.GetData()));
    if (USERID == userId)
    {
        xml.FindElem("incomeId");
        income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("userId");
        income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("date");
        income.setIncomeId(changeToNumber(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("item");
        income.setItem(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("amount");
        income.setIncomeId(strtof(MCD_2PCSZ(xml.GetData())));
    }
    xml.OutOfElem();
    }
}
bool FileWithIncomes::addIncomesToFile(Incomes incomes)
{

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", incomes.getIncomeId());
    xml.AddElem("userId", incomes.getUserId());
    xml.AddElem("date", incomes.getDate());
    xml.AddElem("item", incomes.getItem());
    xml.AddElem("amount", incomes.getAmount());
    xml.Save("users.xml");

}

int FileWithIncomes::changeToNumber(string date)
{
    int fullDate = 0;
    vector<string> tempDate;
    tempDate.clear();
    string yearmonthday = "";
    for (int i=0; i<date.length();i++)
    {
        if(date[i]!='-'){
        yearmonthday = yearmonthday + date[i];
        }
    }
    tempDate.push_back(yearmonthday);
    fullDate = atoi(tempDate[0].c_str());

    return fullDate;
}


