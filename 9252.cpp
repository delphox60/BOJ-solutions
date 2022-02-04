#include <iostream>
#include <string>

using namespace std;

int d[1005][1005];
string sd[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 1005; i++)
    {
        d[0][i] = 0;
        d[i][0] = 0;
        sd[0][i] = "";
        sd[i][0] = "";
    }

    string a, b;
    cin >> a >> b;

    for (int i = 1; i < a.length() + 1; i++)
        for (int j = 1; j < b.length() + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                d[i][j] = max(d[i - 1][j - 1] + 1, d[i - 1][j]);
                if (d[i - 1][j - 1] + 1 > d[i - 1][j])
                    sd[i][j] = sd[i - 1][j - 1] + a[i - 1];
                else
                    sd[i][j] = sd[i - 1][j];
            }
            else
            {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
                if (d[i - 1][j] > d[i][j - 1])
                {
                    sd[i][j] = sd[i - 1][j];
                    continue;
                }
                sd[i][j] = sd[i][j - 1];
            }
        }

    cout << d[a.length()][b.length()] << '\n';
    cout << sd[a.length()][b.length()];
}
