#include <iostream>
#include <string>

using namespace std;

int d[105][105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
        {
            d[0][i][j] = 0;
            d[i][j][0] = 0;
            d[j][0][i] = 0;
        }

    string a, b, c;
    cin >> a >> b >> c;

    for (int i = 1; i < a.length() + 1; i++)
        for (int j = 1; j < b.length() + 1; j++)
            for (int k = 1; k < c.length() + 1; k++)
            {
                if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
                    d[i][j][k] = max(d[i - 1][j - 1][k - 1] + 1, d[i - 1][j][k]);
                else
                    d[i][j][k] = max(d[i - 1][j][k], max(d[i][j - 1][k], d[i][j][k - 1]));
            }

    cout << d[a.length()][b.length()][c.length()];
}
