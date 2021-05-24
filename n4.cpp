#include <iostream>

using namespace std;

int k, n, a[100];

void rev(int* ar, int l)
{
    int* ar2 = new int[l];
    for ( int i = 0; i < l; i++ )
    {
        ar2[i] = ar[i];
    }
    for ( int i = 0; i < l; i++ )
    {
        ar[i] = ar2[(l-1)-i];
    }
}

void solve(int x, int y, int z)
{
    if ( y == 0 )
    {
        if ( x == k )
        {
            int* ar = new int[x];
            for ( int i = 0; i < x; i++ )
            {
                ar[i] = a[i];
            }
            rev(ar, x);
            for ( int i = 0; i < x; i++ )
            {
                cout << ar[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for ( int i = y; i >= z; i-- )
    {
        if ( i >= z )
        {
            a[x] = i;
            solve(x+1, y-i,i);
        }
    }
    return;
}

int main()
{
    cin >> n;
    for ( k = n; k != 0; k-- )
    {
        solve(0,n,1);
    }
}
