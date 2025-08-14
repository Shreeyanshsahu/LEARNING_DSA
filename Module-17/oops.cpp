#include <iostream>
using namespace std;

class Rectangle
{
private:
double length;
    double breadth;

public:
    Rectangle()
    {
        length = 1;
        breadth = 1;
    }

    Rectangle(double side)
    {
        length = side;
        breadth = side;
    }

    Rectangle(double l, double b)
    {
        length = l;
        breadth = b;
    }

    void displayArea()
    {
        double area = length * breadth;
        cout << "Length: " << length << ", Breadth: " << breadth
             << ", Area: " << area << endl;
    }
};

int main()
{

    Rectangle r1;       // Default constructor
    Rectangle r2(5);    // parametrized constructor with same value
    Rectangle r3(4, 6); // Rectangle with different values

    r1.displayArea();
    r2.displayArea();
    r3.displayArea();

    return 0;
}
