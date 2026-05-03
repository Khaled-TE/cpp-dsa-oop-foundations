#include <iostream>
#include <string>
using namespace std;
class Student 
{
    protected:
        string name;
        int age;
        string major;
    public:
        Student(string n, int a, string m) 
        {
            name = n;
            age = a;
            major = m;
        }
        string displayInfo() 
        {
            return name + " " + to_string(age) + " " + major;
        }
};
class GraduateStudent : public Student 
{
    private:
        string thesisTopic;
    public:
        GraduateStudent(string n, int a, string m, string t) : Student(n, a, m) 
        {
            thesisTopic = t;
        }
        string displayInfo() 
        {
            return thesisTopic ;
        }
};

int main() 
{
    Student* p = new GraduateStudent("Alice", 25, "Computer Science", "AI in Healthcare");
    cout << p << endl;
    cout<< (GraduateStudent*)p << endl;
    cout << (Student*)p << endl;
    return 0;
}