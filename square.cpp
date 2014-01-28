// Link to problem description: http://codeforces.com/problemset/problem/194/B


#include <iostream>
#include <math.h>

using namespace std;

unsigned long long mcm(unsigned long long,unsigned long long);
unsigned long long mcd(unsigned long long,unsigned long long);

int main()
{
    int t;
    cin >> t;
    unsigned long long side[t];

    for(int i = 0; i < t;i++)
    {
        cin >> side[i];
    }
    for(int i = 0; i < t;i++)
    {
        if(side[i] == 1)
            cout << 3 << endl;
        else
        {
            unsigned long long a = side[i]*4;
            int b = side[i]+1;

            cout << 1 + mcm(a,b)/b << endl;
        }
    }

    return 0;
}

unsigned long long mcm(unsigned long long a, unsigned long long b)
{
    return a*b/mcd(a,b);
}
unsigned long long mcd(unsigned long long a, unsigned long long b)
{
   unsigned long long tmp;
   if(a < 0)
        a *= -1;
   if(b < 0)
        b *= -1;

   do
   {
      tmp = b;
      b = a % b;
      a = tmp;
   } while (b != 0);
   return a;

}