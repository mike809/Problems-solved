// Link to description of the problem: http://www.spoj.com/problems/PUCMM210/

#include <iostream>
#include <math.h>
#include <vector>
 
#define MOD 1000000003
 
unsigned long long tabla[1000001];
 
using namespace std;
 
int main()
{
        
    tabla[0] = 0;
    unsigned long long tmp = tabla[0];
    
    for(unsigned long long i = 1;i <= 1000000;i++)
        {
                tmp += (((i*i)%MOD)*i%MOD)%MOD;
                tabla[i] = (tmp + tabla[i-1])%MOD;
        }
 
    int t;
    cin >> t;
 
    for(int k = 0;k < t;k++)
    {
        unsigned long long n;
        cin >> n;
 
        cout << tabla[n] << endl;
    }
 
    return 0;
}