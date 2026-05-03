#include <iostream>
using namespace std;

class Student
{
    private:
        string name;
        int grade;
    public:
        Student(string n, int g)
        {
            name = n;
            grade = g;
        }
        string getName()
        {
            return name;
        }
        int getGrade()
        {
            return grade;
        }
};
int search(Student arr[], int size, string target)
{
    for(int i=0; i<size; i++)
        if(arr[i].getName() == target)
            return i;
    return -1;
}
void sort(Student arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        int minindex=i;
        for(int j=i+1; j<size; j++)
            if(arr[j].getGrade() < arr[minindex].getGrade())
                minindex=j;
        swap(arr[i], arr[minindex]);
    }
}
int main()
{
    Student arr[3] = {Student("Bob", 85), Student("Jane", 90), Student("Jim", 75)};
    sort(arr, 3);
    for(int i=0; i<3; i++)
        cout<<arr[i].getName()<<" "<<arr[i].getGrade()<<endl;
    int index = search(arr, 3, "Bob");
    if(index != -1)
        cout<<"Bob is found at index "<<index<<endl;
    else
        cout<<"Bob is not found"<<endl;
    return 0;
}