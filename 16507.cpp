#include <iostream>

using namespace std;

int R, C, Q;

#define ll long long

ll a[1005][1005];
ll d[1005][1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> Q;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= R; i++)
    {
        d[i][0] = 0;
        d[i][1] = a[i][1];
    }

    for (int i = 1; i <= R; i++)
        for (int j = 2; j <= C; j++)
            d[i][j] = d[i][j - 1] + a[i][j];

    for (int i = 0; i < Q; i++)
    {
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;

        ll result = 0;

        for (int i = s1; i <= e1; i++)
            result += (d[i][e2] - d[i][s2 - 1]);

        cout << result / ((e1 - s1 + 1) * (e2 - s2 + 1)) << "\n";
    }
    return 0;
}