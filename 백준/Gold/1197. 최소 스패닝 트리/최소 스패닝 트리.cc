#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int v, e;
vector<int> p(10005, -1);

int find(int n)
{
    if (p[n] < 0)
        return n;
    return p[n] = find(p[n]);
}

int size(int n)
{
    n = find(n);
    return p[n];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    p[b] += p[a];
    p[a] = b;
}

struct edge
{
    int s;
    int e;
    int weight;
    edge() : s(0), e(0), weight(0) {}
    bool operator<(const edge b) const
    {
        return this->weight > b.weight;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long cnt = 0;

    cin >> v >> e;

    priority_queue<edge> pq;

    for (int i = 0; i < e; i++)
    {
        edge e;
        cin >> e.s >> e.e >> e.weight;
        pq.push(e);
    }

    while (!pq.empty())
    {
        edge cur = pq.top();
        pq.pop();

        if (find(cur.s) != find(cur.e))
        {
            cnt += cur.weight;
            merge(cur.s, cur.e);
        }

        if (size(cur.s) == v)
            break;
    }

    cout << cnt << '\n';
}