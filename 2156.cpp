#include <iostream>

using namespace std;

int d[10005][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int wine[10005];
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> wine[i];
    }

    d[1][0] = 0;
    d[1][1] = wine[1];
    d[2][0] = d[1][1];
    d[2][1] = wine[2];
    d[2][2] = wine[1] + wine[2];

    for (int i = 3; i <= n; i++)
    {
        d[i][0] = max(d[i - 1][2], max(d[i - 1][1], d[i - 1][0]));
        d[i][1] = d[i - 1][0] + wine[i];
        d[i][2] = d[i - 1][1] + wine[i];
    }

    cout << max(d[n][1], max(d[n][0], d[n][2])) << "\n";
    return 0;
}