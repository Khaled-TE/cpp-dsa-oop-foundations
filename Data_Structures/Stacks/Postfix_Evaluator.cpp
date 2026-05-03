#include <iostream>
#include <string>
#include <stack>
using namespace std;

int evaluate_a_postfix(string postfix)
{
    stack<int> s;
    for(int i=0; i<postfix.length(); i++)
    {
        if(isdigit(postfix[i]))
            s.push(postfix[i]-'0');
        else
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            switch(postfix[i])
            {
                case '+': s.push(op1+op2); break;
                case '-': s.push(op1-op2); break;
                case '*': s.push(op1*op2); break;
                case '/': s.push(op1/op2); break;
                case '^': s.push(pow(op1,op2)); break;
                default: cout<<"Invalid operator"<<endl;
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string postfix="23*54*+9-";
    cout<<"The result is: "<<evaluate_a_postfix(postfix)<<endl;
    return 0;
}
