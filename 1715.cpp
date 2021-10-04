#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int ip;
        cin >> ip;

        pq.push(ip);
    }

    if (N == 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    int cur;
    int result = 0;
    int tmp;

    while (!pq.empty())
    {
        tmp = pq.top();
        pq.pop();

        if (pq.empty())
            break;

        result += tmp;

        tmp += pq.top();
        result += pq.top();
        pq.pop();

        pq.push(tmp);
    }

    cout << result << '\n';
    return 0;
}