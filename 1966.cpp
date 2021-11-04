#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<int, int>> q;
    priority_queue<int, vector<int>, less<int>> pq;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;

        int n, tar;
        cin >> n >> tar;

        while (!q.empty())
            q.pop();
        while (!pq.empty())
            pq.pop();

        for (int j = 0; j < n; j++)
        {
            int ip;
            cin >> ip;
            q.push({ip, j});
            pq.push(ip);
        }

        while (true)
        {
            pair<int, int> cur = q.front();
            q.pop();
            int primer = pq.top();

            if (cur.first == primer)
            {
                cnt++;
                pq.pop();
                if (cur.second == tar)
                    break;
            }
            else
            {
                q.push(cur);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}