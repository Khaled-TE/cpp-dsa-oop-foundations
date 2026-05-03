#include <iostream>
#include <string>   
using namespace std;

class Employee
{
    protected:
        string name;
        int id;
    public:
        virtual void welcomeMessage() = 0;
        virtual void showDetails() = 0;
        virtual double calculateSalary() = 0;
        virtual ~Employee(){}
};

class FullTimeEmployee : public Employee
{
    private:
        double salary;
    public:
        FullTimeEmployee(string n, int i, double s)
        {
            name = n;
            id = i;
            salary = s;
        }
        void welcomeMessage() override
        {
            cout << "Welcome to the Full-Time Employee Portal!" << endl;
        }
        void showDetails() override
        {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Salary: $" << salary << endl;
        }
        double calculateSalary() override
        {
            return salary;
        }
};

class PartTimeEmployee : public Employee
{
    private:
        double sph;
        int hoursWorked;
    public:
        PartTimeEmployee(string n, int i, double s, int h)
        {
            name = n;
            id = i;
            sph = s;
            hoursWorked = h;
        }
        void welcomeMessage() override
        {
            cout << "Welcome to the Part-Time Employee Portal!" << endl;
        }
        void showDetails() override
        {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Salary per Hour: $" << sph << endl;
            cout << "Hours Worked: " << hoursWorked << endl;
        }
        double calculateSalary() override
        {
            return (sph * hoursWorked);
        }
};

int main() 
{
    Employee* e1 = new FullTimeEmployee("Alice", 101, 5000);
    Employee* e2 = new PartTimeEmployee("Bob", 102, 20, 30);

    e1->welcomeMessage();
    e1->showDetails();
    cout << "Salary: $ " << e1->calculateSalary() << endl << endl;

    e2->welcomeMessage();
    e2->showDetails();
    cout << "Salary: $ " << e2->calculateSalary() << endl;

    delete e1;
    delete e2;

    return 0;
}