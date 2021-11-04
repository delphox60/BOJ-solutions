#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, tar;
    long long result = -1;

    cin >> n >> tar;

    queue<pair<long long, long long>> q;

    q.push({n, 1});

    while (!q.empty())
    {
        pair<long long, long long> cur = q.front();
        q.pop();

        if (cur.first == tar)
        {
            result = cur.second;
            break;
        }

        long long n1 = cur.first * 10 + 1;
        long long n2 = cur.first * 2;
        if (n1 <= tar)
            q.push({n1, cur.second + 1});
        if (n2 <= tar)
            q.push({n2, cur.second + 1});
    }

    cout << result << '\n';

    return 0;
}