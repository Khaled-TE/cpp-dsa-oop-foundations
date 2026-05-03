#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    public:
        stack<int> enq, deq;
        void enqueue(int x)
        {
            if((!enq.empty()&&deq.empty())||(enq.empty()&&deq.empty()))
                enq.push(x);
            else if(enq.empty()&&!deq.empty())
            {
                while(!deq.empty())
                {
                    enq.push(deq.top());
                    deq.pop();
                }
                enq.push(x);
            }
        }
        void dequeue()
        {
            if(enq.empty()&&!deq.empty())
                deq.pop();
            else if(!enq.empty()&&deq.empty())
            {
                while(!enq.empty())
                {
                    deq.push(enq.top());
                    enq.pop();
                }
                deq.pop();
            }
        }
        void display()
        {
            if(enq.empty()&&!deq.empty())
            {
                while(!deq.empty())
                {
                    cout<<deq.top()<<" ";
                    enq.push(deq.top());
                    deq.pop();
                }
            }
            else if(!enq.empty()&&deq.empty())
            {
                while(!enq.empty())
                {
                    deq.push(enq.top());
                    enq.pop();
                }
                while(!deq.empty())
                {
                    cout<<deq.top()<<" ";
                    enq.push(deq.top());
                    deq.pop();
                }
            }
        }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(1);
    q.enqueue(3);
    q.display();
    cout<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
}