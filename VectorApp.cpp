#include <iostream>
using namespace std;

class Vector
{
    private:
        int _size;
        double* _elem;
    public:
        Vector();
        Vector(int);
        Vector(int, double*);
        Vector(const Vector&);
        virtual ~Vector();

        friend ostream& operator<<(ostream&, const Vector&);
        friend istream& operator>>(istream&, Vector&);

        void Display();

        void SummComponents();
        Vector operator+(const Vector&);
        Vector operator*(const Vector&);

};

Vector::Vector()
{
    this->_size = 0; 
    this->_elem = NULL;
}

Vector::Vector(int size)
{
    this->_size = 0; 
    this->_elem = new double[_size];
    for (int i=0; i<_size; i++)
        _elem[i]=0;
};

Vector::Vector(int size, double* elem)
{
    this->_size = size; 
    this->_elem = new double[_size];
    for (int i = 0; i < _size; i++)
        this->_elem[i] = elem[i];
    
};

Vector::Vector(const Vector& v)
{
    this->_size = v._size;
    this->_elem = new double [_size];
    for (int i=0; i<_size; i++)
        _elem[i] = v._elem[i];
};

Vector::~Vector()
{
    delete[] _elem;
};

void Vector::Display()
{
    for (int i = 0; i < _size; i++)
        cout<<_elem[i]<< " ";
    cout << endl;
}


void Vector::SummComponents()
{
    float sum;
    for(int i=0; i<_size; i++)
        sum += _elem[i];
    cout<<"Suma componentelor = "<< sum<<endl;
};

Vector Vector::operator*(const Vector& v)
{
   //Prin produs cartezian, aflam dimensiunea vectorului obinut
   Vector v2;
   v2._size = this->_size * v._size * 2;
   v2._elem = new double[v2._size];

   int i=0, j=0, k=0; 
   while (k < v2._size)
   {
       if(j < v._size)
       {
           v2._elem[k] = this->_elem[i];
           v2._elem[k + 1] = v._elem[j];
           j++;
           k += 2; 
       }
       else
       {
           i++;
           j = 0;
       }
   }
   cout << "Produs Cartezian = ";
   return v2;
   cout<<endl;
}

Vector Vector::operator+(const Vector& v)

{
    Vector v2;
    v2._size = this->_size + v._size;
    v2._elem = new double[v2._size];
    for (int i=0; i < v2._size; i++)
    {
        if (i < this->_size)
            v2._elem[i] = this->_elem[i];
        else
            v2._elem[i] = v._elem[i - this->_size];
    }
    cout << "Concatenare = ";
    return v2;
    cout<<endl;    
}

istream& operator>>(istream& in, Vector& v)
{
    in>>v._size;
    v._elem = new double[v._size];
    for(int i=0;i<v._size;i++)
        in>>v._elem[i];
    return in;
}

ostream& operator<<(ostream& out, const Vector& v)
{
    for (int i = 0; i < v._size; i++)
    {
        out << v._elem[i];
        if (i < v._size - 1)
            out << ", ";
    }
    return out;
}


int main()
{
    Vector v1,v2;
    cin>>v1>>v2;
    v1.SummComponents();
    cout<<v1+v2;
    cout<<v1*v2;
    return 0; 
}

