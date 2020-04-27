#include "FileWithUsers.h"


vector <User> FileWithUsers::loadUsersFromFile()
{
    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", "2");
    xml.AddElem("Login", "bartek");
    xml.AddElem("Password", "456");

    xml.Save("users.xml");
}
