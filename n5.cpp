#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

int stat(char a)
{
    switch (a)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}

string _skobk(string s)
{
    while ( (s[0] == '(') && (s[s.size() - 1] == ')') )
    {
        int in_skobk = 1;
        for ( int i = 1; i < s.size() - 1; i++ )
        {
            char a = s[i];
            if ( a == '(' )
            {
                in_skobk ++;
            }
            else if ( a == ')' )
            {
                in_skobk --;
                if ( in_skobk == 0 )
                {
                    return s;
                }
            }
        }
        s = s.substr(1, s.size() - 2);
    }
    return s;
}

int solve (string s)
{
    s = _skobk(s);
    int in_skobk = 0;
    int min_stat = -1;
    for ( int i = 0; i < s.size(); i++ )
    {
        char a = s[i];
        int p = stat(a);
        if ( p != -1 && in_skobk == 0 && ( min_stat == -1 || p <= stat(s[min_stat]) ) )
        {
            min_stat = i;
        }
        else if ( a == '(' )
        {
            in_skobk ++;
        }
        else if ( a == ')' )
        {
            in_skobk --;
        }
    }
    if ( min_stat != -1 )
    {
        int a, b;
        a = solve(s.substr(0, min_stat));
        b = solve(s.substr(min_stat + 1, s.size()));

        switch (s[min_stat])
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        }
    }
    return atoi (s.c_str());
}

int main()
{
    string s;
    getline(cin, s);
    cout << solve(s);
    return 0;
}
