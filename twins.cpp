// Link to problem description: http://codeforces.com/problemset/problem/160/A

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
    return b < a;
}

int main()
{

    int coins;

    cin >> coins;

    vector<int> values(coins);
    int sum = 0;

    for(int i = 0;i < coins;i++)
    {
        cin >> values[i];
        sum += values[i];
    }


    int min = sum/2 + 1;

    sort(values.begin(), values.end(),cmp);

    sum = 0;
    int count = 0;

    while(sum < min)
    {
        sum += values[count];
        count++;
    }
    cout << count << endl;
    return 0;
}