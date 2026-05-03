#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverse_queue(queue<int> &q)
{
    stack<int> s ;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q1 ;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    cout<<"Queue after: ";
    reverse_queue(q1);
    while (!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
}