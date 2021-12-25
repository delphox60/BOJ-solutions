#include <iostream>
#define ll long long

using namespace std;

ll N, M, K;

ll arr[1000005];
ll tree[4000005];

ll rmd(ll n) { return n % 1000000007; }

ll init(ll low, ll high, ll n)
{
    if (low == high)
        return tree[n] = rmd(arr[low]);

    ll mid = (low + high) / 2;

    return tree[n] = rmd(init(low, mid, 2 * n) * init(mid + 1, high, 2 * n + 1));
}

ll mul(ll s, ll e, ll l, ll r, ll n)
{
    if (r < s || e < l)
        return 1;

    if (s <= l && r <= e)
        return rmd(tree[n]);

    ll m = (l + r) / 2;
    return rmd(mul(s, e, l, m, 2 * n) * mul(s, e, m + 1, r, 2 * n + 1));
}

void update(ll s, ll e, ll idx, ll n, ll oldVal, ll newVal)
{
    if (idx < s || idx > e)
        return;

    tree[n] = rmd(tree[n] / oldVal * newVal);

    if (s == e)
        return;

    ll m = (s + e) / 2;

    update(s, m, idx, 2 * n, oldVal, newVal);
    update(m + 1, e, idx, 2 * n + 1, oldVal, newVal);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (ll i = 1; i <= N; i++)
        cin >> arr[i];

    init(1, N, 1);

    while (M > 0 || K > 0)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            if (arr[b] == 0)
            {
                arr[b] = c;
                init(1, N, 1);
            }
            else
            {
                update(1, N, b, 1, arr[b], c);
                arr[b] = c;
            }
            M--;
        }
        else if (a == 2)
        {
            cout << rmd(mul(b, c, 1, N, 1)) << '\n';
            K--;
        }
    }
}
