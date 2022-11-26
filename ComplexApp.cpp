#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
    private:
        double* _re;
        double* _im;
    public:
        //CONSTRUCTORI & DESTRUCTOR
        Complex();
        Complex(double, double);
        Complex(const Complex&);
        virtual ~Complex();

        //getter & setter
        double getRe();
        double getIm();
        void setRe(double);
        void setIm(double);

        void Display() const;
        Complex& Read();

        //Metode
        Complex Add(const Complex&) const;
        Complex Dif(const Complex&) const;
        Complex Mul(const Complex&) const;
        Complex Conj(const Complex&) const;
        Complex Mod(const Complex&) const;
        
};

Complex::Complex()
{
    _re = new double(0);
    _im = new double(0);
}

Complex::Complex(double re, double im)
{
    this->_re = new double(re);
    this->_im = new double(im);
}

Complex::Complex(const Complex& c)
{
    _re = new double(*c._re);
    _im = new double(*c._im);
}

Complex::~Complex()
{
    delete _re;
    delete _im;
}

void Complex::Display() const
{
    cout<<*_re<<"+i"<<*_im<<endl;
}

Complex& Complex::Read()
{
    cout<<"re: "; cin>>*_re;
    cout<<"im: "; cin>>*_im;

    return *this;
}

double Complex::getRe()
{
    return *_re;
}

double Complex::getIm()
{
    return *_im;
}

void Complex::setRe(double re)
{
    if(re != 0)
        *_re = re;
}

void Complex::setIm(double im)
{
    if(im != 0)
        *_im = im;
}

Complex Complex::Add(const Complex& c) const
{
    Complex summ(*_re + *c._re, *_im + *c._im);
    return summ;
}

Complex Complex::Dif(const Complex& c) const
{
    Complex diff(*_re - *c._re, *_im - *c._im);
    return diff;
}

Complex Complex::Mul(const Complex& c) const
{
    Complex multiply(*_re*(*c._re)-*_im*(*c._im),*_re*(*c._im)+*_im*(*c._re));
    return multiply;
}

Complex Complex::Conj(const Complex& C) const{
    Complex conjugate(*C._re,-*C._im);
    return conjugate;
}

Complex Complex::Mod(const Complex& C) const{
    Complex module(*_re*(*C._re),*_im*(*C._im));
    return module;
}


int main()
{
    Complex c1, c2;
    c1.Read();
    c2.Read();
    c1.Add(c2).Display();
    c1.Dif(c2).Display();
    c1.Mul(c2).Display();
    c1.Mod(c2).Display();
}