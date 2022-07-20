#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define pii pair<int, int>

using namespace std;

vector<vector<int>> v(300001, vector<int>());
vector<bool> visited(300001, false);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;

        v[s].push_back(e);
    }

    queue<pii> q;
    q.push({x, 0});
    visited[x] = true;

    priority_queue<int, vector<int>, greater<int>> result;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        if (cur.second == k)
            result.push(cur.first);

        for (int i : v[cur.first])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push({i, cur.second + 1});
            }
        }
    }

    if (!result.size())
    {
        cout << -1 << '\n';
        return 0;
    }

    while (!result.empty())
    {
        cout << result.top() << '\n';
        result.pop();
    }
}