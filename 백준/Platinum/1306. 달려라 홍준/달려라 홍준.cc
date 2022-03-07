#include <iostream>

using namespace std;

int arr[1000001];
int tree[4000001];
int n, m;

int init(int node = 1, int s = 1, int e = n)
{
    if (s == e)
        return tree[node] = arr[s];
    int m = (s + e) / 2;
    return tree[node] = max(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
}

int getmax(int lo, int hi, int node = 1, int s = 1, int e = n)
{
    if (e < lo || hi < s)
        return 0;
    if (lo <= s && e <= hi)
        return tree[node];

    int m = (s + e) / 2;
    return max(getmax(lo, hi, node * 2, s, m), getmax(lo, hi, node * 2 + 1, m + 1, e));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    init();
    int first;
    int last;
    int curmax = arr[0];

    for (int i = m; i <= n - m + 1; i++)
    {
        first = arr[i - m];
        last = arr[i + m - 1];
        if (curmax == first)
            curmax = getmax(i - m + 1, i + m - 1);
        else if (curmax < last)
            curmax = last;
        cout << curmax << ' ';
    }
}
