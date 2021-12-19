#include <iostream>

using namespace std;

long long N;
long long Q;
long long arr[100005];
long long tree[400005];

long long init(long long s, long long e, long long n)
{
    if (s == e)
        return tree[n] = arr[s];

    long long m = (s + e) / 2;

    return tree[n] = init(s, m, 2 * n) + init(m + 1, e, 2 * n + 1);
}

long long sum(long long s, long long e, long long l, long long r, long long n)
{
    if (s > r || e < l)
        return 0;

    if (l >= s && r <= e)
        return tree[n];

    long long m = (l + r) / 2;

    return sum(s, e, l, m, 2 * n) + sum(s, e, m + 1, r, 2 * n + 1);
}

void update(long long s, long long e, long long n, long long idx, long long diff)
{
    if (idx < s || idx > e)
        return;

    tree[n] += diff;

    if (s == e)
        return;

    long long m = (s + e) / 2;

    update(s, m, 2 * n, idx, diff);
    update(m + 1, e, 2 * n + 1, idx, diff);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    for (long long i = 1; i <= N; i++)
        cin >> arr[i];

    init(1, N, 1);

    for (long long i = 1; i <= Q; i++)
    {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << sum(x <= y ? x : y, x <= y ? y : x, 1, N, 1) << '\n';
        long long diff = b - arr[a];
        arr[a] += diff;
        update(1, N, 1, a, diff);
    }
    return 0;
}
