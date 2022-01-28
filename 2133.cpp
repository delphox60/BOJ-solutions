#include <iostream>
#include <vector>
#define ll long long

using namespace std;

vector<ll> D(16, 0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if (n % 2)
    {
        cout << 0 << '\n';
        return 0;
    }

    D[1] = 3;
    D[2] = 11;
    for (int i = 3; i <= n / 2; i++)
    {
        D[i] += D[i - 1] * 3;
        for (int j = 2; j < i; j++)
            D[i] += D[i - j] * 2;
        D[i] += 2;
    }

    cout << D[n / 2] << '\n';
}