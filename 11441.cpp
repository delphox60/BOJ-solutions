#include <iostream>

using namespace std;

int N, M;

int a[100005];
int d[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    a[0] = 0;
    d[0] = 0;

    for (int i = 1; i <= N; i++)
        d[i] = d[i - 1] + a[i];

    cin >> M;

    for (int i = 1; i <= M; i++)
    {
        int s, e;
        cin >> s >> e;

        cout << d[e] - d[s - 1] << "\n";
    }
    return 0;
}