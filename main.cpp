#include <iostream>
#include "YourBudget.h"
#include "FileWithUsers.h"
#include "FileWithIncomes.h"
#include "FileWithExpences.h"
using namespace std;

int main()
{

    YourBudget yourBudget("users.xml" , "incomes.xml" ,"expences.xml");

    FileWithUsers fileWithUsers("users.xml");
    FileWithExpences fileWithExpences("expences.xml");
    FileWithIncomes fileWithIncomes("incomes.xml");
    int loggedInUserId=0;
    char choise;
    while (true)
    {
        if (yourBudget.isUserLogedIn()==false)
        {
            choise = yourBudget.chooseOptionFromMainMenu();

            switch (choise)
            {
            case '1':
                yourBudget.registrationOfUser();
                break;

            case '2':
                yourBudget.loginOfUser();
                break;
            case '9':
                exit(0);
                break;
            case '3':
                yourBudget.showAllUsers();
                system("pause");
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;

            }
        }
        else
        {
            if (yourBudget.isUserLogedIn() == true)
            choise = yourBudget.chooseOptionFromUserMenu();
            switch (choise)
            {
            case '1':
                yourBudget.addIncome();
                break;
            case '2':
                yourBudget.addExpence();
                break;
            case '3':
                yourBudget.compareExpencesToIncomesInCurrentMonth();
                break;
            case '4':
                yourBudget.compareExpencesToIncomesInPreviousMonth();
                break;
            case '5':
                yourBudget.compareExpencesToIncomesFromCustomDates();
                break;
            case '6':
                yourBudget.changePassword();
                break;
            case '7':
                yourBudget.logoutOfUser();
                break;

            }
        }
    }
    return 0;
}

