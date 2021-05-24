#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream f("input.txt");
    string s, g;
    getline (f, s);
    int mx = 1;
    int tek = 1;
    for ( int i = 1; i <= s.length(); i++ )
    {
        if ( s[i] == s[i-1] )
        {
            tek ++;
            if ( tek > mx )
            {
                mx = tek;
                g = s[i];
            }
        }
        else
        {
            tek = 1;
        }
    }
    cout << g << ' ' << mx;
}
