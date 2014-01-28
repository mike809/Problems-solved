// Link to problem description: http://codeforces.com/problemset/problem/195/A

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int data_per_sec, download_per_sec, total_sec;

    cin >> data_per_sec >> download_per_sec >> total_sec;

    float total_data = data_per_sec * total_sec;

    total_data -= (total_sec * download_per_sec);

    cout << ceil(total_data/download_per_sec) << endl;
    
    return 0;
}