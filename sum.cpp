/*
	Description

	Your task is to find the sum of all integer numbers lying between 1 and N inclusive.

	Link http://coj.uci.cu/24h/problem.xhtml?abb=1049
*/


#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    if(n > 0)
        n = (n*(n + 1))/2;
    else{
        n = -n;
        n = (n*(n + 1))/2;
        n = -n + 1;
    }

    cout << n << endl;
    return 0;
}