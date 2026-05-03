#include <iostream>
using namespace std;

class Rectangle 
{
    protected:
        int length;
        int width;
    public:
        Rectangle(int l, int w) 
        {
            length = l;
            width = w;
        }
        void displayArea() 
        {
            cout << "Area: " << length * width << endl;
        }
};

class Square : public Rectangle
{
    public:
        Square(int l, int w) : Rectangle(l , w){}
        void displayArea()
        {
            cout << "Area: " << length * width << endl;
        }
};

class Cuboid : public Rectangle 
{
    private:
        int height;
    public:
        Cuboid(int l, int w, int h) : Rectangle(l, w) 
        {
            height = h;
        }
        void displayVolume() 
        {
            cout << "Volume: " << length * width * height << endl;
        }
};
int main() 
{ 
    Rectangle R(5, 8);
    Square S(5, 5);
    Cuboid C(5, 8, 10);
    R.displayArea();
    S.displayArea();
    C.displayVolume();
    return 0; 
}