#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool used[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 200000; i++)
        used[i] = false;

    int n;
    int k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({n, 0});
    used[n] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == k)
        {
            cout << cur.second << '\n';
            break;
        }
        if (!used[cur.first - 1] && cur.first - 1 > 0 && cur.first - 1 < 200001)
        {
            q.push({cur.first - 1, cur.second + 1});
            used[cur.first - 1] = true;
        }
        if (!used[cur.first * 2] && cur.first * 2 > 0 && cur.first * 2 < 200001)
        {
            q.push({cur.first * 2, cur.second + 1});
            used[cur.first * 2] = true;
        }
        if (!used[cur.first + 1] && cur.first + 1 > 0 && cur.first + 1 < 200001)
        {
            q.push({cur.first + 1, cur.second + 1});
            used[cur.first + 1] = true;
        }
    }
}