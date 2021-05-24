#include <iostream>

using namespace std;

int main()
{
    int a, b, dv, sum, imax, i2;
    cin >> a >> b;
    sum = 0;
    for ( int i = a; i <= b; i++ )
    {
        if ( i % 2 == 0 && i % 10 != 0 )
        {
            i2 = i;
            dv = 0;
            while ( i2 != 0 )
            {
                dv += i2 % 2;
                i2 = i2 / 2;
            }
            if ( dv == 5 )
            {
                sum += 1;
                imax = i;
            }
        }
    }
    cout << sum << " " << imax;
}
