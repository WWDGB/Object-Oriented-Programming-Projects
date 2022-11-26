#include <iostream>
#include <string.h>
using namespace std;

using namespace std;

//sa se implementeze o clasa MyString pentru lucrul cu siruri de caractere
class MyString
{
    public:
    //constructori
    MyString();
    MyString(char*); //aici se va calcula si size!
    MyString(const MyString&);

    //operator<<
    friend ostream& operator<<(ostream&, const MyString&);

    void DisplayInfo();

    MyString Concat(const MyString&); //nu se modifica obiectul curent
    //se poate supraincarca ulterior operator+
    MyString operator+(const MyString&);
    MyString& ToUpper(); //modifica obiectul curent
    MyString& ToLower();
    MyString& OnlyFirstUpper();

    MyString& Reverse(); //rasturnare sir

    ~MyString();

private:
    char* _elem; //elementele (alocare dinamica in constructori)
    int _size; //lungimea (fara terminatorul de sir)
};

MyString::MyString() 
{
    _elem = new char[1];
    _elem[0] = '\0';
    _size = 0;
}

MyString::MyString(char* s) 
{
    _size = strlen(s);
    _elem = new char[_size + 1];
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = s[i];
    }
    _elem[_size] = '\0';
}

MyString::MyString(const MyString& s) 
{
    _size = s._size;
    _elem = new char[_size + 1];
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = s._elem[i];
    }
    _elem[_size] = '\0';
}

ostream& operator<<(ostream& out, const MyString& s)
{
    out << s._elem;
    return out;
}

void MyString::DisplayInfo()
{
    cout << "Size: " << _size << endl;
    cout << "String: " << _elem << endl;
}

MyString MyString::Concat(const MyString& s)
{
    MyString aux(_elem); //copiaza sirul curent
    aux._size += s._size; //se adauga lungimea sirului s
    aux._elem = new char[aux._size + 1]; 
    for (int i = 0; i < aux._size; i++)
    {
        aux._elem[i] = _elem[i];
    }
    for (int i = 0; i < s._size; i++)
    {
        aux._elem[i + aux._size - s._size] = s._elem[i]; //se adauga sirul s la sfarsitul sirului aux
    }
    aux._elem[aux._size] = '\0';
    return aux;
}

MyString MyString::operator+(const MyString& s)
{
    return Concat(s);
}

MyString& MyString::ToUpper()
{
    for (int i = 0; i < _size; i++)
    {
        if (_elem[i] >= 'a' && _elem[i] <= 'z')
        {
            _elem[i] = _elem[i] - 32;
        }
    }
    return *this;
}

MyString& MyString::ToLower()
{
    for (int i = 0; i < _size; i++)
    {
        if (_elem[i] >= 'A' && _elem[i] <= 'Z')
        {
            _elem[i] = _elem[i] + 32;
        }
    }
    return *this;
}

MyString& MyString::OnlyFirstUpper()
{
    if (_elem[0] >= 97 && _elem[0] <= 122)
        _elem[0] -= 32;
    return *this;
}

MyString& MyString::Reverse()
{
    char aux[_size + 1];
    for (int i = 0; i < _size; i++)
    {
        aux[i] = _elem[i];
    }
    aux[_size] = '\0';
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = aux[_size - i - 1];
    }
    return *this;
}

MyString::~MyString()
{
    delete[] _elem;
}


int main()
{
    //implementare si testare
    MyString s1("Programare");
    MyString s2("OOP");
    MyString s3 = s1 + " " + s2;
    s3.DisplayInfo();
    cout<<endl;
    s3.ToUpper().DisplayInfo();
    cout<<endl;
    s3.ToLower().DisplayInfo();
    cout<<endl;
    s3.OnlyFirstUpper().DisplayInfo();
    cout<<endl;
    s3.Reverse().DisplayInfo();
    return 0;
}