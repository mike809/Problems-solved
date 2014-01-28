/*
Description

We define the parity of an integer N as the sum of the bits in binary
representation computed modulo two. As an example, the number 21 = 10101
has three 1s in its binary representation so it has parity 3 (mod 2), or 1.
In this problem you have to calculate the parity of an integer
1 <= I <= 2147483647 (2^31-1).

Link http://coj.uci.cu/24h/problem.xhtml?abb=1059

*/


#include <iostream>
#include <vector>

using namespace std;

void BinaryParity(int);

int main()
{
    int i;
    cin >> i;
    while(i != 0)
    {
        BinaryParity(i);

        cin >> i;
    }
    return 0;
}

void BinaryParity(int num)
{
    vector<char> binary;
    int sum = 0;

    while(num > 0)
    {
        binary.push_back(num%2+48);

        if(num%2)
            sum++;

        num = num/2;
    }
    cout << "The parity of ";

    for(int i = binary.size()-1;i >= 0;i--)
        cout << binary[i];

    cout << " is " << sum << " (mod 2)." << endl;
}
