#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
    private:
        string title;
        int id;
        static int totalItems;
    public:
        LibraryItem(string t, int i)
        {
            title = t;
            id = i;
            totalItems++;
        }
        virtual void display()
        {
            cout << "Title: " << title << endl;
            cout << "ID: " << id << endl;
            cout << "Total Items: " << totalItems << endl;
        }
        virtual ~LibraryItem()
        {
            cout<< "Destructor called for libraryitem "<< endl;
        }
};


int LibraryItem::totalItems = 0;


class Book : public LibraryItem
{
    private:
        string author;
        int pages;
    public:
        Book(string t, int i, string a , int p) : LibraryItem(t, i)
        {
            author = a;
            pages = p;
        }
        void display ()override
        {
            LibraryItem::display();
            cout << "Author: " << author << endl;
            cout << "Pages: " << pages << endl; 
        }
};


class DVD : public LibraryItem
{
    private:
        int duration;
    public:
        DVD(string t, int i, int du) : LibraryItem(t, i)
        {
            duration = du;
        }
        void display ()override
        {
            LibraryItem::display();
            cout << "Duration: " << duration << endl; 
        }
};


class SpecialEdition : public Book, public DVD
{
    private:
        string specialFeatures;
    public:
        SpecialEdition(string t, int i, string a, int p, int du, string sf) : Book(t, i, a, p), DVD(t, i, du)
        {
            specialFeatures = sf;
        }
        void display ()override
        {
            Book::display();
            DVD::display();
            cout << "Special Features: " << specialFeatures << endl; 
        }
};

int main()
{
    LibraryItem *item1 = new Book("C++ Programming", 101, "Bjarne Stroustrup", 500);
    LibraryItem *item2 = new DVD("Inception", 102, 148);
    Book *item3 = new SpecialEdition("The Matrix", 103, "Lana Wachowski", 136, 136, "Behind the Scenes");
    item1->display();
    item2->display();
    item3->display();
    delete item1;
    delete item2;
    delete item3;
    return 0;
}
