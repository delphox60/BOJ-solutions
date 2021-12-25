#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

class pii
{
private:
    int first;
    int second;

public:
    int getFirst() { return first; }
    int getSecond() { return second; }
    pii(int first, int second) : first(first), second(second) {}
    bool operator<(pii r)
    {
        if (first == r.first)
            return second > r.second;
        return first < r.first;
    }

    bool operator==(pii r)
    {
        return first == r.first && second == r.second;
    }

    bool operator>=(pii r)
    {
        return (*this > r || *this == r);
    }

    bool operator<=(pii r)
    {
        return !(*this < r || *this == r);
    }

    bool operator>(pii r)
    {
        return !(*this < r || *this == r);
    }
};

using namespace std;

int N;
vector<pii> arr(1000005);
vector<int> last(4000005, 0);
vector<int> tree(4000005, 0);

int getMaxLen(int s, int e, int l, int r, int n)
{
    if (r < s || e < l)
        return 0;

    if (s <= l && r <= e)
        return tree[n];

    int m = (r + l) / 2;
    return max(getMaxLen(s, e, l, m, 2 * n), getMaxLen(s, e, m + 1, r, 2 * n + 1));
}

int update(int s, int e, int idx, int n)
{
    if (idx < s || idx > e)
        return 0;

    if (s == e)
        return tree[n] = getMaxLen(1, idx, 1, N, 1) + 1;

    int m = (s + e) / 2;

    return tree[n] = max(update(s, m, idx, 2 * n), update(m + 1, e, idx, 2 * n + 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        arr.push_back(pii(x, i));
    }

    sort(arr.begin(), arr.end());

    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        update(1, N, it->getSecond(), 1);
    }

    cout << getMaxLen(1, N, 1, N, 1) << '\n';
}
