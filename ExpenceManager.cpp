#include <ExpenceManager.h>


void ExpenceManager::showAllExpences() {
    system("cls");
    if (!expences.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i=0; i<incomes.size(); i++) {
            cout << endl << "Id wydatku: " << expences[i].getIncomeId() << endl;
            cout << "Id uzytkownika:     " << expences[i].getUserId() << endl;
            cout << "Data:               " << expences[i].getDate() << endl;
            cout << "Wydatek:            " << expences[i].getItem() << endl;
            cout << "Kwota:              " << expences[i].getAmount() << endl;
        }
        cout << endl;
    } else {
        cout << endl << "Lista wydatkow jest pusta." << endl << endl;
    }
    system("pause");

}
void ExpenceManager::addExpence() {
    Expence expence = enterNewExpence();
    expences.push_back(expence);
    fileWithUsers.addIncomeToFile(expence);
    cout << endl << "Wprowadzono nowy wydatek." << endl << endl;
    system("pause");
}

Expence ExpenceManager::enterNewExpence() {
    Expence expence;
    expence.setExpenceId(getIdOfNewExpence());
    expence.getUserId(LOGGED_IN_USER_ID);
    string date, item;
    string amount;
    char choise;
    cout << "Wpisz date przychodu: ";
    pause(1000);
    cout << endl << "Czy dzis uzyskales przychod? (T,N): ";
    choice = getSign();
    if (choice=='T')||(choice=='t') {
        int correctDate=todaysDate();
        expence.setDate(correctDate);
    } else {
    cout << "Wpisz date w formacie rrr-mm-dd:";
    getline(cin ,date);
    if (checkIfDateIsCorrect(date)==false){
        cout << "Niepoprawna data. Wpisz ponownie: ";
        cin.clear();
        getline(cin ,date);
        checkIfDateIsCorrect(date);
    }
        expence.setDate(FileWithIncomes.changeToNumber(date));
    }
    cout << "Z jakiego tytulu: ";
    getline(cin, item);
    expence.setItem(item);
    cout << "Podaj kwote przychodu: ";
    cin >> amount;
    changeCommaToDotInAmount(amount);
    expence.setAmount(amount);

    return expence;
}
int ExpenceManager::todaysDate() {
    vector<int> date;
    date.clear();
    int currentDate;
    time_t t = time(0);
    struct tm * now = localtime( & t );

    if(((now->tm_mon+1)<10)&&((now->tm_mday)<10)) {
        date.push_back(now->tm_year + 1900);
        date.push_back(0);
        date.push_back(now->tm_mon+1);
        date.push_back(0);
        date.push_back(now->tm_mday);
    } else if ((now->tm_mday)<10) {
        date.push_back(now->tm_year + 1900);
        date.push_back(now->tm_mon+1);
        date.push_back(0);
        date.push_back(now->tm_mday);
    } else if((now->tm_mon+1)<10) {
        date.push_back(now->tm_year + 1900);
        date.push_back(0);
        date.push_back(now->tm_mon+1);
        date.push_back(now->tm_mday);
    } else {
        date.push_back(now->tm_year + 1900);
        date.push_back(now->tm_mon+1);
        date.push_back(now->tm_mday);
    }

    return date;
}
char ExpenceManager::getSign() {
    string income = "";
    char sign  = {0};
    while (true) {
        getline(cin, income);

        if (income.length() == 1) {
            sign = income[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

}
int ExpenceManager::getIdOfNewIncome() {
    if (expences.empty() == true)
        return 1;
    else
        return expences.back().getIncomeId() + 1;
}

float ExpenceManager::changeCommaToDotInAmount(string amount) {
    float correctAmount;
    for (int i=0; i<amount.length(); i++) {
        if (amount[i]==",")
            amount[i]==".";
    }
    correctAmount=atof(amount.C_str());
    return correctAmount;
}
float ExpenceManager::getIncomesFromCurrentMonth() {
    int date = todaysDate();
    float totalExpences = 0;
    for (int i=0; i<6; i++) {
        if (expences[i].getDate()==date[i]) {
            totalExpences = totalExpences + expences.getAmount[i];
        }
    }
    return totalExpences;
}
void ExpenceManager::getExpencesFromPreviousMonth() {
    int date = todaysDate();
    for (int i=0; i<date.length(); i++) {
        if((date[4]==1)&&(date[5]==0]) {
            date[4]=0;
            date[5]=9;
        } else {
            date[5]=date[5]-1;
        }
    }
    float totalExpences = 0;
    for (int i=0; i<6; i++) {
        if (expences[i].getDate()==date[i]) {
            totalIncomes = totalIncomes + expences.getAmount[i];
        }
    }
    return totalExpences;
}
void ExpenceManager::getExpencesFromCustomDate() {
    string startingDate, endDate;
    float totalExpences = 0;
    cout << "Wpisz date poczatkowa (w formacie rrrr-mm-dd: ";
    getline (cin, startingDate);
    int beginDate = FileWithExpences.changeToNumber(startingDate);
    cout << "Wpisz date koncowa (w formacie rrrr-mm-dd: ";
    getline (cin, endDate);
    int finishDate = FileWithExpences.changeToNumber(startingDate);

    for (int i = 0; i<expences.size(); i++) {
        if ((expences[i].getDate() > beginDate)&&(expences[i].getDate() > endDate)) {
            totalExpences = totalExpences + expences.getAmount[i];
        }
    }
    return totalExpences;
}
bool ExpenceManager::checkIfDateIsCorrect(string date) {
    int day, month, year;
    string seperating = "";
    vector<string> tempDate;
    for (int i=0; i<date.length(); i++) {
        if(date[i]!="-"){
            seperating = seperating + date[i];
        }
        else{
            tempDate.push_back(seperating);
            seperating = "";
        }
    }
    tempDate.push_back(seperating);
    int year = atoi(tempDate[0]);
    if ((year < 2000) || (year > 2021)) {
        cout<< "Nieprawidlowy rok. Wpisz ponownie: ";
    }
    int month = atoi(tempDate[1]);
    if (month > 12) {
        cout << "Nieprawidlowy miesiac. Wpisz ponownie: ";
    }
    int day = atoi(tempDate[2]);
    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
        if (day > 30) {
            cout << "Miesiac " << month <<" ma 30 dni. Wpisz ponownie: ";
        }
    } else if (month == 2) {
        bool leapyear (year);
        if (leapyear == true)
            if (day > 29) {
                cout << "Rok "<< year <<" jest przestepny. Zatem miesiac " << month << " ma maksymalnie 29 dni. Wpisz ponownie: ";
            } else if (day > 28) {
                cout << "Miesiac " << month << " ma maksymalnie 28 dni. Wpisz ponownie: ";
            }
    } else {
        if (day > 31) {
            cout << "Miesiac " << month << " ma maksymalnie 31 dni. Wpisz ponownie: ";
        }
    }
}
bool ExpenceManager::leapyear (int year) {
    if(( year%4 == 0 && year%100 != 0) || ( year%400 == 0 ));
    else
        false;
}

