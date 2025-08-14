#include <iostream>
using namespace std;

class Rectangle
{

public:
    double &length;
    double &width;
    // Rectangle(double &l, double &b) : length(l), width(b) {}
    void set_data(){
        
    }
    void showarea()
    {
        double area = length * width;
        cout << "Length: " << length << ", Breadth: " << width << ", Area: " << area << endl;
    }
};

int main()
{
    double l = 32;
    double b = 23;
    Rectangle r1(l,b);
    r1.showarea();

}