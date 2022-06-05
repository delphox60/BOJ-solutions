#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    long long d1[105];
    d1[1] = 1;
    d1[2] = 1;
    d1[3] = 1;

    for (int i = 4; i < 101; i++)
    {
        d1[i] = d1[i - 2] + d1[i - 3];
    }

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << d1[n] << "\n";
    }
    return 0;
}