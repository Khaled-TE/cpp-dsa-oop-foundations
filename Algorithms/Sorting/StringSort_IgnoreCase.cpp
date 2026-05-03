#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() 
{
    int n = 4;
    string name [4];
    string temp [4];
    name [0] = "apple";
    name [1] = "Banana";
    name [2] = "cherry";
    name [3] = "Apricot";
    
    cout<<"Before: ";
    for(int i = 0; i< n ; i++)
    {
        cout<<name[i]<<" ";
        temp[i] = name[i];
        transform(temp[i].begin(), temp[i].end(), temp[i].begin(), ::tolower);
    }

/*We merge this into the first loop to reduce runtime
    for(int i =0 ; i < n  ; i ++)
    {
        temp[i] = name[i];
        transform(temp[i].begin(), temp[i].end(), temp[i].begin(), ::tolower);
    }*/
    for(int i =0 ; i < n - 1 ; i ++)
    {
        for(int j = 0 ; j < (n - i -1) ; j++)
        {   
            
            if(temp[j]>temp[j+1] )
            {
                swap(name[j], name[j+1]);
                swap(temp[j], temp[j+1]);
            }
        }
    }
    cout<<"\nAfter: ";
    for(int i = 0; i< n ; i++)
    {
        cout<<name[i]<<" ";
    }
return 0;
}
