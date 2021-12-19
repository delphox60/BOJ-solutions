#include <iostream>

using namespace std;

int N;
int Q;
int arr[100005];
int tree[400005];

int init(int s, int e, int n)
{
    if (s == e)
        return tree[n] = arr[s];

    int m = (s + e) / 2;

    return tree[n] = init(s, m, 2 * n) + init(m + 1, e, 2 * n + 1);
}

int sum(int s, int e, int l, int r, int n)
{
    if (s > r || e < l)
        return 0;

    if (l >= s && r <= e)
        return tree[n];

    int m = (l + r) / 2;

    return sum(s, e, l, m, 2 * n) + sum(s, e, m + 1, r, 2 * n + 1);
}

void update(int s, int e, int n, int idx, int diff)
{
    if (idx < s || idx > e)
        return;

    tree[n] += diff;

    if (s == e)
        return;

    int m = (s + e) / 2;

    update(s, m, 2 * n, idx, diff);
    update(m + 1, e, 2 * n + 1, idx, diff);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    init(1, N, 1);

    for (int i = 1; i <= Q; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << sum(x <= y ? x : y, x <= y ? y : x, 1, N, 1) << '\n';
        int diff = b - arr[a];
        arr[a] += diff;
        update(1, N, 1, a, diff);
    }
    return 0;
}
