#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define pii pair<int, int>

using namespace std;

int n, k, t;
vector<vector<int>> station2line(101, vector<int>());
vector<vector<int>> line2station(11, vector<int>());
vector<bool> visited(101, false);
map<int, int> stationNum;
int idx = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int s;
        int station;
        cin >> s;

        for (int j = 0; j < s; j++)
        {
            cin >> station;

            if (stationNum.find(station) == stationNum.end())
                stationNum.insert({station, idx++});

            station = stationNum.find(station)->second;

            station2line[station].push_back(i);
            line2station[i].push_back(station);
        }
    }
    cin >> t;

    queue<pii> q;

    for (int line : station2line[stationNum.find(0)->second])
    {
        for (int station : line2station[line])
        {
            q.push({station, 0});
            visited[station] = true;
        }
    }

    int result = -1;
    t = stationNum.find(t)->second;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        vector<int> lines = vector<int>();

        if (cur.first == t)
            result = cur.second;

        for (int i : station2line[cur.first])
            lines.push_back(i);

        for (int line : lines)
            for (int i : line2station[line])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push({i, cur.second + 1});
                }
            }
    }

    cout << result;
}