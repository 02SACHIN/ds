#include <iostream>
#include <string>
#include "Stack_t.h"
using std::cin; using std::cout; using std::endl;

bool isOperator(char c)
{
    if((c == '+' ||c == '-' ||c == '*' ||c == '/' ) == true )
    {
        return true;
    }

    return false;
    
}

double eval_Prefix(string exp)
{
    Stack<double> s;

    for(int i = exp.size()-1; i >= 0; i--)
    {
        if(isOperator(exp[i]) == false)
        {
            s.push(exp[i]-'0');
        }

        else
        {
            double o1 =s.top_el();
            s.pop();
            double o2 = s.top_el();
            s.pop();

            if(exp[i]=='+')
            {
                s.push(o1+o2);
            }

            else if(exp[i]=='-')
            {
                s.push(o1-o2);
            }

            else if(exp[i]=='*')
            {
                s.push(o1*o2);
            }

            else if(exp[i]=='/')
            {
                s.push(o1/o2);
            }
            
            else
            {
                cout<<"Sorry the given operator in not supported."<<endl;
            }
        }
    }

    cout<<"The result of the expression is:"<<s.top_el()<<endl;
}

int main()
{
    string s;
    cout<<"Please enter an expression in postfix format:";
    cin>>s;

    eval_Prefix(s);
}
