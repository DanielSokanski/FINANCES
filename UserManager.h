#ifndef USERMANAGER_H
#define USERMANAGER_H

#include<iostream>
#include<vector>
#include<windows.h>
//#include "FileWithUsers.h"
#include "User.h"
using namespace std;

class UserManager
{
    //int loggedInUserId;
    vector<User> users;
    User enterNewUserData();
    int getIdOfNewUser();
    bool doesLoginExist(string login);
    //FileWithUsers fileWithUsers;

public:
    /*UserManager(string userFileName) : fileWithUsers(userFileName){
    loggedInUserId = 0;
    //users = fileWithUsers.loadUsersFromFile();
    };*/
    int loggedInUserId = 0;
    bool isUserLogedIn();
    char chooseOptionFromMainMenu();
    char getLine();
    char chooseOptionFromUserMenu();
    void registrationOfUser();
    void showAllUsers();
};




#endif
