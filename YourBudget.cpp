#include "YourBudget.h"

bool YourBudget::isUserLogedIn()
{
    userManager.isUserLogedIn();
}

char YourBudget::chooseOptionFromMainMenu()
{
    userManager.chooseOptionFromMainMenu();
}

char YourBudget::chooseOptionFromUserMenu()
{
    userManager.chooseOptionFromUserMenu();
}

void YourBudget::registrationOfUser()
{
    userManager.registrationOfUser();
}

void YourBudget::showAllUsers()
{
    userManager.showAllUsers();
}
