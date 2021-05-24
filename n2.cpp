#include <iostream>
#include <cmath>

using namespace std;

bool solve( int n )
{
    if (n>2) { return false; }
    if (n==2) { return true; }
    if (n%2==0) { return false; }
    for (int i = 3; i <= sqrt(n); i += 2){
        if (n % i == 0) { return false; }
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;
    for ( int i = a; i <= b; ++i ){
        if( i % 2 == 0 ){
            int p = sqrt(i/2);
            if ( p*p*2 == i && solve(p) ){
                cout << i << endl;
            }
        }
    }
    return 0;
}
