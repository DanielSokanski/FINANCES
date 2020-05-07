#include "Expences.h"

void Expences::setIncomeId(int newIncomeId)
{
    if (newIncomeId >=0)
        incomeId=newIncomeId;
}
void Expences::setUserId(int newUserId)
{
    userId=newUserId;
}
void Expences::setDate(int newDate)
{
    date=newDate;
}
void Expences::setItem(string newItem)
{
    item=newItem;
}
void Expences::setAmount(float newAmount)
{
    amount=newAmount;
}
int Expences::getIncomeId()
{
    return incomeId;
}
int Expences::getUserId()
{
    return userId;
}
int Expences::getDate()
{
    return date;
}
string Expences::getItem()
{
    return item;
}
float Expences::getAmount()
{
    return amount;
}
