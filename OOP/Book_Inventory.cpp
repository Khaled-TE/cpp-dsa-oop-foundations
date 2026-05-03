#include <iostream>
using namespace std;

class Book
{
    private:
        int ISBN;
        string title;
    public:
          
        void seter(int i, string t)
        {
            ISBN=i;
            title=t;
        }
        int Get_ISBN()
        {
            return ISBN;
        } 
        string Get_title()
        {
            return title;
        }
};
void selection_sort(Book arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        int minin=i;
        for(int j=i+1; j<size; j++)
            if(arr[j].Get_ISBN()<arr[minin].Get_ISBN())
                minin=j;
        swap(arr[i],arr[minin]);
    }
}
int binary_search(Book arr[], int size, int target)
{
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        int mid=(high-low)/2+low;
        if(arr[mid].Get_ISBN()==target)
            return mid;
        else if(arr[mid].Get_ISBN()>target)
            high=mid-1;
        else   
            low=mid+1;
    }
    return -1;
}
int main()
{
    Book B[3];
    B[0].seter(1453,"ahmen");
    B[1].seter(3251,"sameh");
    B[2].seter(2563,"khaled");
    selection_sort(B,3);
    int targetin=binary_search(B,3,2563);
    if(targetin==-1)
        cout<<"Book not found";
    else
    {
        cout<<"Book found at index: "<<targetin;
        cout<<"\n Book's title is "<<B[targetin].Get_title();
    }
}