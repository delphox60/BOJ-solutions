#include <iostream>

using namespace std;

int N, M;

int city[105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            city[i][j] = 0;

    for (int j = 1; j <= M; j++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        if (city[s][e])
            city[s][e] = min(city[s][e], cost);
        else
            city[s][e] = cost;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
            {
                if (city[j][i] && city[i][k] && j != k)
                {
                    if (city[j][k])
                        city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
                    else
                        city[j][k] = city[j][i] + city[i][k];
                }
            }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << city[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}