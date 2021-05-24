#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>

using namespace std;

void stakk(stack<int> s)
{
    stack<int> s2 = s;
    while ( !s2.empty() )
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> nam;
    string s;
    int a, b;
    bool flag = true;
    while ( cin >> s )
    {
        if ( s == "+" )
        {
            if ( nam.size() < 2 )
            {
                flag = false;
                break;
            }
            a = nam.top();
            nam.pop();
            b = nam.top();
            nam.pop();
            nam.push(a+b);
        }
        else if( s == "-" )
        {
            if ( nam.size() < 2 )
            {
                flag = false;
                break;
            }
            a = nam.top();
            nam.pop();
            b = nam.top();
            nam.pop();
            nam.push(b-a);
        }
        else if( s == "*" )
        {
            if ( nam.size() < 2 )
            {
                flag = false;
                break;
            }
            a = nam.top();
            nam.pop();
            b = nam.top();
            nam.pop();
            nam.push(b*a);
        }
        else if( s == "/" )
        {
            if ( nam.size() < 2 )
            {
                flag = false;
                break;
            }
            a = nam.top();
            nam.pop();
            if ( a == 0 )
            {
                flag = false;
                break;
            }
            b = nam.top();
            nam.pop();
            nam.push(b / a);
        }
        else
        {
            nam.push(atoi(s.c_str()));
        }
    }
    if ( !flag )
    {
        cout << nam.top();
    }
    else
    {
        cout << "ERROR";
    }
}
