#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> indegree(32001, 0);
vector<vector<int>> adj(32001);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    while (m--)
    {
        int s, e;
        cin >> s >> e;
        indegree[e]++;
        adj[s].push_back(e);
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (!indegree[i])
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (auto it = adj[cur].begin(); it != adj[cur].end(); it++)
        {
            indegree[*it]--;
            if (!indegree[*it])
                q.push(*it);
        }
    }
}