#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge
{
    int s;
    int e;
    int cost;
    edge(int s, int e, int c) : s(s), e(e), cost(c) {}
    bool operator<(const edge E) const
    {
        return this->cost > E.cost;
    }
}

int s_cost[303];
int l_cost[303][303];
int n;
vector<int> p(303, -1);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<edge> pq;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s_cost[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> l_cost[i][j];
            if (l_cost[i][j] <= s_cost[i] && l_cost[i][j] <= s_cost[j])
                pq.push(edge(i, j, l_cost[i][j]));
        }
}