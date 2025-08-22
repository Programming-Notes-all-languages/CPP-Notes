#include <iostream>
using namespace std;

//class definition for Shape abstract, base class
class Shape
{
    public:
        //pure virtual function allowing derived classes to calculate the shapes' areas
        virtual double area() const = 0;
        //pure virtual function allowing derived classes to display the shapes' information
        virtual void display() const = 0;
        virtual ~Shape() {}
};

//class definition for Circle derived class
class Circle : public Shape
{
    //private member attribute for the circle's radius
    double radius;
    
    public:
        //constructor instantiating a Circle instance
        Circle(double Radius) : radius(Radius) {}
        //member function which calculates the circle's area
        double area() const override { return radius * radius * 3.1415; }
        //member function which displays the shape's name and area
        void display() const override { cout << "Circle, Area: " << area() << endl; }
};

//class definition for Rectangle derived class
class Rectangle : public Shape
{
    //private member attributes for the rectangle's width and height
    double width, height;

    public:
        //constructor instantiating a Rectangle instance
        Rectangle(double Width, double Height) : width(Width), height(Height) {}
        //member function which calculates the rectangle's area
        double area() const override { return width * height; }
        //member function which displays the shape's area and name
        void display() const override { cout << "Rectangle, Area: " << area() << endl;}
};

int main()
{
    //declaration of array of type Shape * containing four shapes
    Shape *shapes[4];

    //instantiating the shapes to be circles and rectangles
    shapes[0] = new Circle(2.5);
    shapes[1] = new Circle(2.3);
    shapes[2] = new Rectangle(2, 3);
    shapes[3] = new Rectangle(4, 9);

    //for loop which iterates over the array of shapes
    for (int i = 0; i < 4; i++)
    {
        //display the shape's information, then freeing it from memory
        shapes[i]->display();
        delete shapes[i];
    }

    return 0;
}