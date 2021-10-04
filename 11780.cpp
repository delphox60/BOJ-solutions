#include <iostream>

using namespace std;

const int INF = 1e9 + 10;

int city[105][105];
int nxt[105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            nxt[i][j] = INF;
            city[i][j] = INF;
        }

    for (int i = 0; i < M; i++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        city[s][e] = min(city[s][e], cost);
        nxt[s][e] = e;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
            {
                if (j == k)
                    continue;
                if (city[j][i] + city[i][k] < city[j][k])
                {
                    city[j][k] = city[j][i] + city[i][k];
                    nxt[j][k] = nxt[j][i];
                }
            }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << ((city[i][j] == INF) ? 0 : city[i][j]) << ' ';
        cout << '\n';
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (nxt[i][j] == INF)
                cout << 0 << '\n';
            else
            {
                int tmp = i;
                int t = 0;
                int path[N];
                while (tmp != j)
                {
                    path[t] = tmp;
                    tmp = nxt[tmp][j];
                    t++;
                }
                cout << t + 1 << ' ';
                for (int k = 0; k < t; k++)
                    cout << path[k] << ' ';
                cout << j << '\n';
            }
        }
    }

    return 0;
}
