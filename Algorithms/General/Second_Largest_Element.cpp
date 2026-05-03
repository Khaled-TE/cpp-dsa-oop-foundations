#include <iostream>
using namespace std;

void sec_largest(int arr[], int size){
    int largest=0;
    int second_largest=0;
    for(int i=0; i < size; i++)
    {
        if(arr[i]>largest)
        {
            second_largest=largest;
            largest=arr[i];
        }
        else if(arr[i]>second_largest)
        second_largest=arr[i];
    }
    cout<<"The second largest number is: "<<second_largest;
}

int main()
{
    int s=7;
    int arr[]={5,18,2,9,32,65,56};
    sec_largest(arr,s);
    return 0;
}