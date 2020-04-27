#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include<iostream>
#include<vector>
#include<fstream>
#include <cstdlib>
#include "User.h"
#include "Markup.h"
//#include "TextFile.h"

using namespace std;

class FileWithUsers
{
    CMarkup xml;
    const string USERS_FILE_NAME;
    vector<User> users;
public:
    //FileWithUsers(string nazwaPlikuZUzytkownikami): TextFile(nazwaPlikuZUzytkownikami){};
    vector <User> getUserFromFile();
    void addUserToFile(User users);
    void saveAllUsersToFile(vector<User> &users);
};


#endif
