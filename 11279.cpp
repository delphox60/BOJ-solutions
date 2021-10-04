#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int cmd;
        cin >> cmd;

        if (cmd)
            pq.push(cmd);
        else
        {
            if (!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << 0 << '\n';
        }
    }
    return 0;
}