// Link to problem description: http://codeforces.com/problemset/problem/198/A

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double k,b,n,t;
    int x;

    cin >> k >> b >> n >> t;

    if(k > 1)
        x = floor(log((t*(k-1)+b)/((k-1)+b)) / log(k));
    else
        x = floor((t-k)/b);

    if((x = n-x) >= 0)
        cout << x << endl;
    else
        cout << "0" << endl;

    return 0;
}