#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int cost[501][501];
int sum[501];

// int cost(int st, int end)
// {
//     if (st == end)
//         return totalCost[st][end] = cost[st];

//     if (st + 1 == end)
//         return totalCost[st][end] = cost[st] + cost[end];

//     if (totalCost[st][end] != INF)
//         return totalCost[st][end];

//     totalCost[st][end] = min(totalCost[st][end], cost(st, st) + 2 * cost(st + 1, end));

//     for (int m = st + 1; m < end; m++)
//         totalCost[st][end] = min(totalCost[st][end], 2 * (cost(st, m) + cost(m + 1, end)));

//     totalCost[st][end] = min(totalCost[st][end], 2 * cost(st, end - 1) + cost(end, end));

//     return totalCost[st][end];
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;

        sum[0] = 0;

        for (int i = 1; i <= k; i++)
        {
            int tmp;
            cin >> tmp;
            sum[i] = sum[i - 1] + tmp;
        }

        for (int i = 1; i < k; i++)
        {
            int s = 1;
            int e = i + 1;
            for (int j = 0; j < k - i; j++)
            {
                cost[s][e] = INF;
                for (int m = e - i; m <= e - 1; m++)
                {
                    cost[s][e] = min(cost[s][e], cost[s][m] + cost[m + 1][e] + sum[e] - sum[s - 1]);
                }
                s++;
                e++;
            }
        }

        cout << cost[1][k] << endl;
    }
}