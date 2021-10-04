#include <iostream>

using namespace std;

long long d[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[1] = 1;
    d[2] = 3;

    int n;
    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        d[i] = d[i - 1] + 2 * d[i - 2];
        d[i] %= 10007;
    }

    cout << d[n] << "\n";
    return 0;
}