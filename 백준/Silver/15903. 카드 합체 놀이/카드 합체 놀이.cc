#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while (m--)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum = a + b;
        a = sum;
        b = sum;
        pq.push(a);
        pq.push(b);
    }

    long long result = 0;
    while (!pq.empty())
    {
        result += pq.top();
        pq.pop();
    }

    cout << result << endl;
}