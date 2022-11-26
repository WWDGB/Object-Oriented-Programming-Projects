#include <iostream>

using namespace std;
class Polinom
{
	public:
		Polinom(); //pol. null
		Polinom(int); //se transmite doar gradul, toti coeficientii vor fi zero
		Polinom(int, double*);
		Polinom(const Polinom&);

		//operator<< pentru afisare!
		friend ostream& operator<<(ostream& ,const Polinom& );

		void Display();
		//operator>> pentru citire! atentie se aloca spatiu corespunzator
        friend istream& operator>>(istream& ,Polinom& );
		//suma a doua polinoame!
		Polinom Sum(const Polinom&);

		//inmultire
		Polinom Mult(const Polinom&);

		//derivare
		Polinom& Derivare(); //se afecteaza obiectul curent *this

		//calcul P(x) = valoare intr-un punct
		double GetValue(double);

		~Polinom();
	private:
		int _grad; //grad 0 pentru polinomul constant; grad -1 pentru polinomul null
		double* _coef; //vector de lungime grad + 1
};
Polinom::Polinom()
{
    _grad=-1;
    _coef=new double(0);
}
Polinom::Polinom(int grad)
{
    _grad=grad;
    _coef=new double[_grad+1];
    for(int i=0;i<grad+1;i++)
        _coef[i]=0;
}
Polinom::Polinom(int grad, double* coef)
{
    _grad=grad;
    _coef=new double[_grad+1];
    for(int i=0;i<grad+1;i++)
        _coef[i]=coef[i];
}
Polinom::Polinom(const Polinom& s)
{
    _grad=s._grad;
    _coef=new double[_grad+1];
    for(int i=0;i<_grad+1;i++)
        _coef[i]=s._coef[i];
}
Polinom::~Polinom()
{
    delete[] _coef;
}

ostream& operator<<(ostream& out, const Polinom& x)
{
    for(int i=x._grad;i>=1;i--)
    {
        if(x._coef[i]!=0)
        {
            if(x._coef[i]!=1)
            out<<x._coef[i];
            out<<"X^"<<i<<"+";
        }
    }
    out<<x._coef[0];
    return out;
}
void Polinom::Display()
{
    for(int i=_grad;i>=1;i--)
    {
        if(_coef[i]!=0)
        {
            if(_coef[i]!=1)
            cout<<_coef[i];
            cout<<"X^"<<i<<"+";
        }
    }
    cout<<_coef[0];
}
istream& operator>>(istream& in, Polinom& x)
{
    cout<<"Gradul polinomului=";in>>x._grad;
    delete[] x._coef;
    x._coef=new double[x._grad+1];
    for(int i=0;i<=x._grad;i++)
        {cout<<"X^"<<i<<'=';in>>x._coef[i];}
    return in;
}
Polinom Polinom::Sum(const Polinom &x) {
    Polinom a;
    int grad_min;

    if(x._grad > _grad)
    {
        a._grad=x._grad;
        grad_min=_grad;

    }
    else
    {
        a._grad=_grad;
        grad_min=x._grad;
    }


    delete[] a._coef;
    a._coef=new double[a._grad+1];
    for(int i=0;i<=grad_min;i++)
        {a._coef[i]=_coef[i]+x._coef[i];}


    if(x._grad > _grad)
        for(int i=grad_min+1;i<=a._grad;i++)
            a._coef[i]=x._coef[i];
    else
        for(int i=grad_min+1;i<=a._grad;i++)
            a._coef[i]=_coef[i];
    return a;
}
Polinom& Polinom::Derivare()
{
    double *s;
    s=new double[_grad+1];
    for(int i=0;i<=_grad;i++)
        s[i]=_coef[i];
    delete[] _coef;
    _coef=new double[_grad];
    for(int i=0;i<=_grad-1;i++)
        _coef[i]=(i+1)*s[i+1];
    _grad--;
    return (*this);
}
double Polinom::GetValue(double x)
{
    double s=0,valx;
    for(int i=0;i<=_grad;i++)
    {
        valx=1;
        for(int j=1;j<=i;j++)
            valx=valx*x;
        s+=_coef[i]*valx;
    }
    return s;
}
Polinom Polinom::Mult(const Polinom& x)
{
    Polinom a(_grad+x._grad);
    a._coef=new double[a._grad+1];
    for(int i=0;i<=a._grad;i++)
        for(int j=0;j<=i;j++)
            if(j<=_grad && i-j<=x._grad)
                a._coef[i]+=_coef[j]*x._coef[i-j];
    return a;
}
int main()
{
    double q[3]={1,1,1};
    Polinom a,b(2),c(2,q),d(c);
    cin>>a;
    cout<<a.Sum(c)<<endl;
    cout<<a.Mult(c)<<endl;
    cout<<a.GetValue(2)<<endl;
    cout<<a.Derivare();
    return 0;
}
