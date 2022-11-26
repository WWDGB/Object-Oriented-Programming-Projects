#include <iostream>
#include <string.h>
using namespace std;

class MyDateTime
{
private:
    int _year;
    int _month;
    int _day;
    int _hour;
    int _min;
    int _sec;

public:
    MyDateTime();
    MyDateTime(const char *); // din formatul: "dd:mm:yyyy hh:mm:ss" se extrag datele obiectului
    MyDateTime(const MyDateTime &);
    MyDateTime(int, int, int, int, int, int);

    char *ToString() const; // se returneaza formatul "dd:mm:yyyy hh:mm:ss"

    // afisare: "dd:mm:yyyy hh:mm:ss"
    friend ostream &operator<<(ostream &, const MyDateTime &);

    MyDateTime &operator=(const MyDateTime &);

    MyDateTime &AddYears(int);  // data curenta se modifica adaugand un numar de ani
    MyDateTime &AddDays(int);   // data curenta se modifica adaugand un numar de zile
    MyDateTime &AddMonths(int); // data curenta se modifica adaugand un numar de luni

    bool operator==(const MyDateTime &) const; // verificare egalitate
    bool operator<(const MyDateTime &) const;
    bool operator>(const MyDateTime &) const;
};

MyDateTime::MyDateTime()
{
    _year = 0;
    _month = 0;
    _day = 0;
    _hour = 0;
    _min = 0;
    _sec = 0;
};

MyDateTime::MyDateTime(const char* date) //din formatul: "dd:mm:yyyy hh:mm:ss" se extrag datele obiectului
{
    _day = atoi(date); //extragere ziua
    date += 3; //se positioneaza la separatorul de luni
    //idem de aici
    _month = atoi(date);
    date += 3;
    _year = atoi(date);
    date += 5;
    _hour = atoi(date);
    date += 3;
    _min = atoi(date);
    date += 3;
    _sec = atoi(date);
}

MyDateTime::MyDateTime(const MyDateTime& date)
{
    this->_year = date._year;
    this->_month = date._month;
    this->_day = date._day;
    this->_hour = date._hour;
    this->_min = date._min;
    this->_sec = date._sec;
}

MyDateTime::MyDateTime(int day, int month, int year, int hour, int min, int sec)
{
    _year = year;
    _month = month;
    _day = day;
    _hour = hour;
    _min = min;
    _sec = sec;
};

char *MyDateTime::ToString() const
{
    char *s = new char[20];
    sprintf(s, "%02d:%02d:%04d %02d:%02d:%02d", _day, _month, _year, _hour, _min, _sec);
    return s;
};

ostream &operator<<(ostream& out, const MyDateTime& date)
{
    out << date._day << date._month << date._year << date._hour << date._min << date._sec;
    return out;
}

MyDateTime& MyDateTime::AddYears(int years)
{
    _year += years;
    return *this;
}

MyDateTime& MyDateTime::AddMonths(int months)
{
    if(_month + months > 12)
    {
        _year += (_month + months) / 12;
        _month = (_month + months) % 12;
    }
    else
    {
        _month += months;
    }
    return *this;
}

MyDateTime& MyDateTime::AddDays(int days)
{
     while (days > 0) { //daca inca mai am zile de adaugat
        if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0) { //daca anul este bisect
            if (_month == 2 && _day == 29) { //daca suntem in februarie si ziua curenta este 29
                _day = 1;
                _month++;
            }
            else if (_month == 12 && _day == 31) { //daca suntem in decembrie si ziua curenta este 31
                _day = 1;
                _month = 1;
                _year++;
            }
            else if (_day == 30 && (_month == 4 || _month == 6 || _month == 9 || _month == 11)) { //daca suntem in luna cu 30 de zile si ziua curenta este 30
                _day = 1;
                _month++;
            }
            else if (_day == 31 && (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10)) { //daca suntem in luna cu 31 de zile si ziua curenta este 31
                _day = 1;
                _month++;
            }
            else { //daca nu suntem in niciunul din celelalte cazuri
                _day++;
            }
        }
        else { //daca anul nu este bisect
            if (_month == 2 && _day == 28) { //daca suntem in februarie si ziua curenta este 28
                _day = 1;
                _month++;
            }
            else if (_month == 12 && _day == 31) { //daca suntem in decembrie si ziua curenta este 31
                _day = 1;
                _month = 1;
                _year++;
            }
            else if (_day == 30 && (_month == 4 || _month == 6 || _month == 9 || _month == 11)) { //daca suntem in luna cu 30 de zile si ziua curenta este 30
                _day = 1;
                _month++;
            }
            else if (_day == 31 && (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10)) { //daca suntem in luna cu 31 de zile si ziua curenta este 31
                _day = 1;
                _month++;
            }
            else { //daca nu suntem in niciunul din celelalte cazuri
                _day++;
            }
        }
        days--; //scadem numarul de zile de adaugat
    }
    return *this;
}

bool MyDateTime::operator==(const MyDateTime& date) const
{
    return _year == date._year && _month == date._month && _day == date._day && _hour == date._hour && _min == date._min && _sec == date._sec;
}

bool MyDateTime::operator<(const MyDateTime& date) const
{
    return _year < date._year || _month < date._month || _day < date._day || _hour < date._hour || _min < date._min || _sec < date._sec;
}

bool MyDateTime::operator>(const MyDateTime& date) const{
    return _year > date._year || _month > date._month || _day > date._day || _hour > date._hour || _min > date._min || _sec > date._sec;
}

int main()
{
    
}