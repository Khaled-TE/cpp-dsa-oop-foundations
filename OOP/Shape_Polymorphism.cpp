#include <iostream>
using namespace std;

class Shape
{
    public:
        virtual double area() = 0;
};

class Circle : public Shape
{
    private:
        double red;
    public:
        Circle (double r)
        {
            red=r;
        }
        double area ()override
        {
            return 3.14*red*red;
        }
};

class Rectangle : public Shape
{
    private:
        double width, height;
    public:
        Rectangle (double w, double h)
        {
            width=w;
            height=h;
        }
        double area () override
        {
            return width*height;
        }
};

int main()
{
    Shape* s[5];
    s[0]= new Circle(10);
    s[1]= new Circle(4);
    s[2]= new Circle(7);
    s[3]= new Rectangle(10, 4);
    s[4]= new Rectangle(3, 7);
    for(int i = 1; i<5; i++)
    {
        double key=s[i]->area();
        int j=i-1;
        while(j>=0 && s[j]->area()>s[j+1]->area())
        {
            swap(s[j], s[j+1]);
            j--;
        }
    }
    for(int i=0; i<5; i++)
    {
        cout<<s[i]->area()<<" ";
    }
}