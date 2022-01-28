#include <iostream>
#include <vector>
#define ll long long

using namespace std;

vector<vector<ll>> D(202, vector<ll>(202));
vector<vector<ll>> Sum(202, vector<ll>(202, 1));

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
    {
        D[i][1] = 1;
    }

    for (int j = 1; j <= k; j++)
    {
        D[0][j] = 1;
        for (int i = 1; i <= n; i++)
        {
            D[i][j] = Sum[i][j - 1];
            Sum[i][j] = (Sum[i - 1][j] + D[i][j]) % 1000000000;
        }
    }
    cout << D[n][k] << '\n';
}
