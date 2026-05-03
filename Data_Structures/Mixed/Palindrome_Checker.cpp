#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool ispalindrome(string &text)
{
    stack<char> s;
    queue<char> q;
    for(char c : text)
    {
        if(isalpha(c))
        {
            c = tolower(c);
            s.push(c);
            q.push(c);
        }
    }
    for(int i=0; i<(s.size()/2); i++)
    {
        if(!(s.top()==q.front()))
            return false;
        else
        {
            s.pop();
            q.pop();
        }
    }
    return true;
}

int main()
{
    string text= "Level";
    if(ispalindrome(text))
        cout<<"Palindrome";
    else 
        cout<<"Not palindrome";
}