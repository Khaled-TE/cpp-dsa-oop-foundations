#include <iostream>
using namespace std;

int BubbleSort(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    return 0;
}

int BinarySearch(int arr[], int size, int target)
{
    int maxin=size-1;
    int minin=0;
    while(minin<=maxin)
    {
        int mid=(maxin-minin)/2+minin;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target)
            maxin=mid-1;
        else
            minin=mid+1;
    }
    return -1;
}

int main()
{
    int arr[]={5, 2, 8, 10, 9};
    int size=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,size);
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    if(BinarySearch(arr, size, 10)==-1)
        cout<<"Target not found\n";
    else
        cout<<"Target found at index "<<BinarySearch(arr, size, 10)<<endl;
    return 0;
}