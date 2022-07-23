#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> pairs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    pairs min;
    priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
    while (n--)
    {
        int tmp;
        cin >> tmp;

        if (!tmp)
        {
            if (!pq.empty())
            {
                min = pq.top();
                cout << pq.top().second << '\n';
                pq.pop();
                continue;
            }
            cout << 0 << '\n';

            continue;
        }

        pq.push({abs(tmp), tmp});
    }
}