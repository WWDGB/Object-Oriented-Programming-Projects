#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

//Sa se implementeze o ierarhie de clase Shape, Circle, Line, Rectangle, Triangle, Square
//Point2D
class Point2D
{
    public:
        Point2D(int=0,int=0);
        Point2D(const Point2D&);

         void SetX(int);
         void SetY(int);

         int GetX() const; //este const pentru ca la inheritent nu se poate modifica obiectul curent
         int GetY() const; 

    private:
        int x;
        int y;
};
///----implementare Point2D
Point2D::Point2D(int x, int y) : x(x), y(y) {}
Point2D::Point2D(const Point2D& p) 
{
    x = p.GetX();
    y = p.GetY();
}
void Point2D::SetX(int x) 
{
    this->x = x;
}
void Point2D::SetY(int y)
{
    this->y = y;
}
int Point2D::GetX() const
{
    return this->x;
}
int Point2D::GetY() const
{
    return this->y;
}

//clasa de baza
class Shape
{
    public:
        Shape();
        Shape(char*, Point2D);
        Shape(const Shape&);

        virtual void DisplayInfo();
        virtual double GetArea(); //calculeaza aria
        virtual double GetPerimeter(); //calculeaza perimteru

        virtual ~Shape();//virtual
    protected: //am schimbat din private in protected pentru altfel nu functiona
         char* name; //numele
        Point2D origin; //originea
};

///implementare class Shape
Shape::Shape()
{
    this->name = NULL;
    this->origin = Point2D(0,0);
}
Shape::Shape(char* name, Point2D origin)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->origin = origin;
}
Shape::Shape(const Shape& s)
{
    this->name = new char[strlen(s.name) + 1];
    strcpy(this->name, s.name);
    this->origin = s.origin;
}
void Shape::DisplayInfo()
{
    cout << "Nume: " << this->name << endl;
    cout << "Origine: " << this->origin.GetX() << " " << this->origin.GetY() << endl;
}
double Shape::GetArea()
{
    return 0;
}
double Shape::GetPerimeter()
{
    return 0;
}
Shape::~Shape()
{
    delete[] this->name;
}

class Line : public Shape
{
    public:
        Line();
        Line(char*, Point2D, Point2D);
        Line(const Line&);

        //redefinire metode mostenite
        void DisplayInfo();
        double GetArea(); //calculeaza aria
        double GetPerimeter(); //calculeaza perimteru
    private:
       Point2D other;
};
///implementare class Line
Line::Line() : Shape()
{
    this->other = Point2D(0,0);
}
Line::Line(char* name, Point2D origin, Point2D other) : Shape(name, origin)
{
    this->other = other;
}
Line::Line(const Line& l) : Shape(l)
{
    this->other = l.other;
}
void Line::DisplayInfo()
{
    Shape::DisplayInfo();
    cout << this->other.GetX() << " " << this->other.GetY() << endl;
}
double Line::GetArea()
{
    return 0;
}
double Line::GetPerimeter()
{
    return 0;
}

class Circle : public Shape
{
    public:
        Circle();
        Circle(char*, Point2D, int);
        Circle(const Circle&);

        //redefinire metode mostenite
        void DisplayInfo();
        double GetArea(); //calculeaza aria
        double GetPerimeter(); //calculeaza perimteru
    private:
        double radius;
};
///implementare class Circle
Circle::Circle() : Shape()
{
    this->radius = 0;
}
Circle::Circle(char* name, Point2D origin, int radius) : Shape(name, origin)
{
    this->radius = radius;
}
Circle::Circle(const Circle& c) : Shape(c)
{
    this->radius = c.radius;
}
void Circle::DisplayInfo()
{
    Shape::DisplayInfo();
    cout << this->radius << endl;
}
double Circle::GetArea()
{
    return 3.14 * this->radius * this->radius;
}
double Circle::GetPerimeter()
{
    return 2 * 3.14 * this->radius;
}

class Rectangle : public Shape
{
    public:
        Rectangle();
        Rectangle(char*, Point2D, int, int);
        Rectangle(const Rectangle&);

        //redefinire metode mostenite
        void DisplayInfo();
        double GetArea(); //calculeaza aria
        double GetPerimeter(); //calculeaza perimteru
    private:
        Point2D other;
};
///implementare class Rectangle
Rectangle::Rectangle() : Shape()
{
    this->other = Point2D(0,0);
}
Rectangle::Rectangle(char* name, Point2D origin, int width, int height) : Shape(name, origin)
{
    this->other = Point2D(width, height);
}
Rectangle::Rectangle(const Rectangle& r) : Shape(r)
{
    this->other = r.other;
}
void Rectangle::DisplayInfo()
{
    Shape::DisplayInfo();
    cout << this->other.GetX() << " " << this->other.GetY() << endl;
}
double Rectangle::GetArea()
{
    return this->other.GetX() * this->other.GetY();
}
double Rectangle::GetPerimeter()
{
    return 2 * (this->other.GetX() + this->other.GetY());
}

class Triangle : public Shape
{
  public:
    Triangle(); 
    Triangle(char*, Point2D, Point2D, Point2D);
    Triangle(const Triangle&);

    //redefinire metode mostenite
    void DisplayInfo();
    double GetArea(); //calculeaza aria
    double GetPerimeter(); //calculeaza perimteru

  private:
        Point2D point1;
        Point2D point2;
};
///implementare class Triangle
Triangle::Triangle() : Shape()
{
    this->point1 = Point2D(0,0);
    this->point2 = Point2D(0,0);
}
Triangle::Triangle(char* name, Point2D origin, Point2D point1, Point2D point2) : Shape(name, origin)
{
    this->point1 = point1;
    this->point2 = point2;
}
Triangle::Triangle(const Triangle& t) : Shape(t)
{
    this->point1 = t.point1;
    this->point2 = t.point2;
}
void Triangle::DisplayInfo()
{
    Shape::DisplayInfo();
    cout << this->point1.GetX() << " " << this->point1.GetY() << endl;
    cout << this->point2.GetX() << " " << this->point2.GetY() << endl;
}
double Triangle::GetArea()
{
    double a = this->origin.GetX() - this->point1.GetX();
    double b = this->origin.GetY() - this->point1.GetY();
    double c = this->origin.GetX() - this->point2.GetX();
    double d = this->origin.GetY() - this->point2.GetY();
    return abs(a * d - b * c) / 2;

}
double Triangle::GetPerimeter()
{
    double a = this->origin.GetX() - this->point1.GetX();
    double b = this->origin.GetY() - this->point1.GetY();
    double c = this->origin.GetX() - this->point2.GetX();
    double d = this->origin.GetY() - this->point2.GetY();
    return sqrt(a * a + b * b) + sqrt(c * c + d * d);
}

class Square : public Shape
{
    public:
        Square();
        Square(char*, Point2D, int);
        Square(const Square&);

        //redefinire metode mostenite
        void DisplayInfo();
        double GetArea(); //calculeaza aria
        double GetPerimeter(); //calculeaza perimteru
    private:
        double length;
};
///implementare class Square
Square::Square() : Shape()
{
    this->length = 0;
}
Square::Square(char* name, Point2D origin, int length) : Shape(name, origin)
{
    this->length = length;
}
Square::Square(const Square& s) : Shape(s)
{
    this->length = s.length;
}
void Square::DisplayInfo()
{
    Shape::DisplayInfo();
    cout << this->length << endl;
}
double Square::GetArea()
{
    return this->length * this->length;
}
double Square::GetPerimeter()
{
    return 4 * this->length;
}

int main()
{
    Shape* shapes[5];
    shapes[0] = new Line("Line1", Point2D(5,1), Point2D(2,7));
    shapes[1] = new Circle("Circle1", Point2D(3,7), 3);
    shapes[2] = new Rectangle("Rectangle1", Point2D(3,4), 4, 5);
    shapes[3] = new Triangle("Triangle1", Point2D(5,2), Point2D(6,10), Point2D(7,-3));
    shapes[4] = new Square("Square1", Point2D(8,9), 9);
    for(int i = 0; i < 5; i++)
    {
        shapes[i]->DisplayInfo();
        cout << "Area: " << shapes[i]->GetArea() << endl;
        cout << "Perimeter: " << shapes[i]->GetPerimeter() << endl;
    }
    return 0;
}
