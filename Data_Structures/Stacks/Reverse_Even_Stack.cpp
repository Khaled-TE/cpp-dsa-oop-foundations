#include <iostream>
#include <stack>
using namespace std;

void reverseeven(stack<int> m)
{
    stack<int> inverse, even, einverse;

    while(!m.empty())
    {
        if(m.top()%2==0)
        {
            inverse.push(m.top());
            even.push(m.top());
        }
        else
        {
            inverse.push(m.top());
        }
        m.pop();
    }
    while(!even.empty())
    {
        einverse.push(even.top());
        even.pop();
    }
    while(!inverse.empty())
    {
        if(inverse.top()%2==0)
        {
            m.push(einverse.top());
            einverse.pop();
        }
        else
        {
            m.push(inverse.top());
        }
        inverse.pop();
    }
    while(!m.empty())
    {
        cout<<m.top()<<" ";
        m.pop();
    }
}
int main()
{
    stack<int> m;
    m.push(1);
    m.push(2);
    m.push(4);
    m.push(7);
    m.push(6);
    m.push(3);
    reverseeven(m);
    return 0;
}