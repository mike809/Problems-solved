// Link to description of the problem: http://www.spoj.com/problems/ADDREV/

#include <stdio.h>

int invertir(int);

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);
    int sumandos = 2*n;
    int arreglo[sumandos];
    int total[n];

    for(int i = 0; i < sumandos;i++)
    {
        scanf("%d", &arreglo[i]);
        arreglo[i] = invertir(arreglo[i]);
    }

    for(int i = 0;i < n;i++)
        total[i] = arreglo[i*2] + arreglo[(i*2)+1];

    for(int i = 0;i < n;i++)
       total[i] = invertir(total[i]);

    for(int i = 0;i < n;i++)
        printf("%d\n", total[i]);

    return 0;
}

int invertir(int num)
{
    int temp = 0;

    while(num > 0)
    {
        temp *= 10;
        temp += num % 10;
        num /= 10;
    }

    return temp;
}
