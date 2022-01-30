#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
long long countVal = 0;
vector<long long> arr(500000);

void dq(long long l, long long h)
{
    if (l == h)
        return;

    long long m = (l + h) / 2;

    dq(l, m);
    dq(m + 1, h);

    long long lIdx = l;
    long long rIdx = m + 1;

    while (lIdx <= m && rIdx <= h)
    {
        if (arr[lIdx] > arr[rIdx])
        {
            countVal += (m + 1 - lIdx);
            rIdx++;
            continue;
        }
        lIdx++;
    }
    sort(arr.begin() + l, arr.begin() + h + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    dq(0, n - 1);
    cout << countVal << '\n';

    return 0;
}
