#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() 
{
    int n = 4;
    string name [4] = {"apple", "Banana", "Apricot", "cherry"};

    cout<<"Before: ";
    for(int i = 0; i< n ; i++)
    {
        cout<<name[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {   
            if(name[j] > name[j+1])
            {
                swap(name[j], name[j+1]);
            }
        }
    }
    cout<<"After: ";
    for(int i = 0; i< n ; i++)
    {
        cout<<name[i]<<" ";
    }

return 0;
}
