#include <iostream>
#include <string.h>

using namespace std;

//mostenire in c++
//administrarea persoanelor (contacte)
//in cadrul unei universitati
//clasa generala Contact
//clase particulare (subclase): Student, Employee,
//Profesor

class Contact
{
  public:
        Contact();
        Contact(char*, char*, char*, char*);
        Contact(const Contact&);

        //getters, setters (tema!!)

        virtual void DisplayInfo();

        virtual ~Contact();

  private:
        char* name;
        char* email;
        char* address;
        char* phone;
};

Contact::Contact()
{
    name = 0;
    email = 0;
    address = 0;
    phone = 0;
}
Contact::Contact(char* name, char* email, char* address, char* phone)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->email = new char[strlen(email) + 1];
    strcpy(this->email, email);

    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);

    this->phone = new char[strlen(phone) + 1];
    strcpy(this->phone, phone);
}
Contact::Contact(const Contact& c)
{
    this->name = new char[strlen(c.name) + 1];
    strcpy(this->name, c.name);

    this->email = new char[strlen(c.email) + 1];
    strcpy(this->email, c.email);

    this->address = new char[strlen(c.address) + 1];
    strcpy(this->address, c.address);

    this->phone = new char[strlen(c.phone) + 1];
    strcpy(this->phone, c.phone);
}
void Contact::DisplayInfo()
{
    cout<<"name: "<<name<<endl;
    cout<<"email: "<<email<<endl;
    cout<<"address: "<<address<<endl;
    cout<<"phone: "<<phone<<endl;
}
Contact::~Contact()
{
    delete[] name;
    delete[] email;
    delete[] address;
    delete[] phone;
    
}

class Student : public Contact
{
    public:
        //constructorii nu se mostenesc direct!
        //se vor implementa efectiv (explicit)!
        Student();
        Student(char*, char*, char*, char*, char*);
        Student(const Student&);

        ~Student();

        //getter,setter (faculty) - tema
        char* getFaculty();
        void setFaculty();

        //redefinirea metodei mostenite (DisplayInfo)
        void DisplayInfo();

    private:
        char* faculty;
};

Student::Student():Contact() //datele mostenite sunt initializate folosind constructorii din baza!
{
    faculty = 0; //initializez doar datele concrete (specifice)
}
Student::Student(char* name,  char* email, char* address, char* phone, char* faculty):Contact(name, email, address, phone)
{
    this->faculty = new char[strlen(faculty) + 1];
    strcpy(this->faculty, faculty);
}
Student::Student(const Student& s):Contact(s)
{
    this->faculty = new char[strlen(s.faculty) + 1];
    strcpy(this->faculty, s.faculty);
}
void Student::DisplayInfo()
{
        //apelam versiunea mostenita
        Contact::DisplayInfo();
        cout<<"faculty: "<<faculty<<endl;
}
Student::~Student()
{
    delete[]faculty;
}

class Employee : public Contact
{   
    public:
        Employee();
        Employee(char*, char*, char*, char*, char*, double);
        Employee(const Employee&);

        ~Employee();

        //getter,setter (salary) - tema
        double getSalary();
        void setSalary();

        //redefinirea metodei mostenite (DisplayInfo)
        void DisplayInfo();

    private:
        double salary;
        char* depart;
};

Employee::Employee():Contact()
{
    salary = 0;
    depart = 0;
}
Employee::Employee(char* name,  char* email, char* address, char* phone, char* depart, double salary):Contact(name, email, address, phone)
{
    this->depart = new char[strlen(depart) + 1];
    strcpy(this->depart, depart);
    this->salary = salary;
}
Employee::Employee(const Employee& e):Contact(e)
{
    this->depart = new char[strlen(e.depart) + 1];
    strcpy(this->depart, e.depart);
    this->salary = e.salary;
}
double Employee::getSalary()
{
    return salary;
}
void Employee::setSalary()
{
    this->salary = salary;
}
void Employee::DisplayInfo()
{
    Contact::DisplayInfo();
    cout<<"depart: "<<depart<<endl;
    cout<<"salary: "<<salary<<endl;
}
Employee::~Employee()
{
    delete[] depart;
    
}

class Professor : public Employee
{
    public:
        Professor();
        Professor(char*, char*, char*, char*, char*, double, char*);
        Professor(const Professor&);

        ~Professor();

        //getter,setter (grad) - tema
        char* getGrad();
        void setGrad();
        
        //redefinirea metodei mostenite (DisplayInfo)
        void DisplayInfo();
    private:
        char* grad;
};
Professor::Professor():Employee()
{
    grad = 0;
}
Professor::Professor(char* name,  char* email, char* address, char* phone, char* depart, double salary, char* grad):Employee(name, email, address, phone, depart, salary)
{
    this->grad = new char[strlen(grad) + 1];
    strcpy(this->grad, grad);
}
Professor::Professor(const Professor& p):Employee(p)
{
    this->grad = new char[strlen(p.grad) + 1];
    strcpy(this->grad, p.grad);
}
char* Professor::getGrad()
{
    return grad;
}
void Professor::setGrad()
{
    this->grad = grad;
}
void Professor::DisplayInfo()
{
    Employee::DisplayInfo();
    cout<<"grad: "<<grad<<endl;
}
Professor::~Professor()
{
    delete[] grad;
    cout<<"Professor::~Professor()"<<endl;
}

void Process(Contact* c)
{
    c->DisplayInfo();
}

int main()
{
    Contact c("Popescu", "popescu@upit.ro", "Pitesti", "112");
    Student s("Vasile", "vasile@gmail.com", "Bucuresti", "911", "Info");
    c.DisplayInfo();
    cout<<endl;
    s.DisplayInfo();
    cout<<endl;
    Employee e("David", "david@gmail.com", "Pitesti", "420", "Info", 12.5);
    e.DisplayInfo();
    cout<<endl;
    Professor p("Abel", "abel@gmail.com", "Hawai", "07 n-am cartela", "Fizica", 13.5, "Lector Universitar");
    p.DisplayInfo();
    cout<<endl;
    cout<< "Testare instantiere folosind base class pointer"<<endl;
    cout<<endl;
    char name[]="Stefan cel Mare";
    char email[]="StefTheBig@gmailcom";
    char address[]="Moldova";
    char phone[]="0000000000";
    char faculty[]="Istorie";
    double salary = 14.5;
    char depart[]="Istoria Romaniei";
    char grad[]="Decan";

    Contact* sPoiner = new Student(name,email, address, phone, faculty);
    sPoiner->DisplayInfo();
    cout<<endl;

    Contact* ePoiner = new Employee(name, email, address, phone, depart, salary);
    ePoiner->DisplayInfo();
    cout<<endl;

    Contact* pPoiner = new Professor(name,email, address, phone, depart, salary, grad);
    pPoiner->DisplayInfo();
    cout<<endl;

    cin.get();
    return 0;
}
