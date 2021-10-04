#include <iostream>

using namespace std;

int N, M;

#define ll long long

ll a[1000005];
ll d[1000005];
ll n[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
        n[i] = 0;

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    d[1] = a[1] % M;

    for (int i = 2; i <= N; i++)
        d[i] = (d[i - 1] + a[i]) % M;

    for (int i = 1; i <= N; i++)
        n[d[i]]++;

    long long result = 0;

    if (n[0] != 1)
        result += n[0];

    for (int i = 0; i < M; i++)
        result += (n[i] * (n[i] - 1)) / 2;

    cout << result << '\n';
    return 0;
}