#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int j = 0; j < N; j++)
    {
        int op;
        cin >> op;

        pq.push(op);
    }
    for (int i = 1; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int op;
            cin >> op;

            pq.push(op);
            pq.pop();
        }

    cout << pq.top() << "\n";
    return 0;
}