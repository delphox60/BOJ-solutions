#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> v[101];
    int table[101][100001];

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            table[i][j] = table[i - 1][j];
            if (v[i].first <= j)
                table[i][j] = max(v[i].second + table[i - 1][j - v[i].first], table[i][j]);
        }
    }

    cout << table[n][k] << endl;
}