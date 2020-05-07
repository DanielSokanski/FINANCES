#include "FileWithExpences.h"

vector <Expences> FileWithExpences::loadExpencesOfLoggedInUser()
{
    int date;
    Expence expence;
    vector <Expences> expences;
    CMarkup xml;
    xml.Load( "expences.xml" );
    xml.FindElem( "Expences" );
    xml.IntoElem();
    while(xml.FindElem( "Expence" ))
    {
    xml.IntoElem();
    xml.FindElem("userId");
    int USERID = atoi(MCD_2PCSZ(xml.GetData()));
    if (USERID == userId)
    {
        xml.FindElem("incomeId");
        expence.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("userId");
        expence.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("date");
        expence.setIncomeId(changeToNumber(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("item");
        expence.setItem(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("amount");
        expence.setIncomeId(strtof(MCD_2PCSZ(xml.GetData())));
    }
    xml.OutOfElem();
    }
}
bool FileWithExpences::addExpencesToFile(Expences expences)
{

    bool fileExists = xml.Load( "expences.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expences");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expence");
    xml.IntoElem();
    xml.AddElem("incomeId", expences.getIncomeId());
    xml.AddElem("userId", expences.getUserId());
    xml.AddElem("date", expences.getDate());
    xml.AddElem("item", expences.getItem());
    xml.AddElem("amount", expences.getAmount());
    xml.Save("users.xml");

}

int FileWithExpences::changeToNumber(string date)
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


