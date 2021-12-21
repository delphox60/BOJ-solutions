#include <iostream>
#define ll long long

using namespace std;

int N;
int arr[100005];
ll segTree[400005];
int minTree[400005];

ll maxPt = -1;
int maxS, maxE;

ll segInit(int s, int e, int n)
{
    if (s == e)
        return segTree[n] = arr[s];
    int m = (s + e) / 2;
    return segTree[n] = segInit(s, m, 2 * n) + segInit(m + 1, e, 2 * n + 1);
}

int minInit(int s, int e, int n)
{
    if (s == e)
        return minTree[n] = arr[s];
    int m = (s + e) / 2;
    return minTree[n] = min(minInit(s, m, 2 * n), minInit(m + 1, e, 2 * n + 1));
}

int sum(int s, int e, int l = 1, int r = N, int n)
{
    if (r < s || e < l)
        return 0;
    if (s <= r && l <= e)
        return segTree[n];
    int m = (l + r) / 2;
    return sum(s, e, l, m, 2 * n) + sum(s, e, m, r, 2 * n + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (ll i = 1; i <= N; i++)
        cin >> arr[i];

    minInit(1, N, 1);
    segInit(1, N, 1);

    cout << maxPt << '\n'
         << maxS << ' ' << maxE << '\n';
}
