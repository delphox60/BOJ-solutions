#include <iostream>

using namespace std;

int d[1005][3];
int cost[1005][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i][0];
        cin >> cost[i][1];
        cin >> cost[i][2];
    }

    d[1][0] = cost[1][0];
    d[1][1] = cost[1][1];
    d[1][2] = cost[1][2];

    for (int i = 2; i <= N; i++)
    {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + cost[i][0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + cost[i][1];
        d[i][2] = min(d[i - 1][1], d[i - 1][0]) + cost[i][2];
    }

    cout << min(min(d[N][0], d[N][1]), d[N][2]) << "\n";
    return 0;
}