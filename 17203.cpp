#include <iostream>

using namespace std;

int N, M;

int a[1005];
int d[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    a[0] = 0;
    d[0] = 0;

    for (int i = 1; i <= N; i++)
        d[i] = d[i - 1] + max(a[i], a[i - 1]) - min(a[i], a[i - 1]);

    for (int i = 1; i <= M; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << d[e] - d[s] << "\n";
    }
    return 0;
}