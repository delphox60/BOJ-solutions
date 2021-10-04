#include <iostream>

using namespace std;

int N;
int area[10015];
int M;

long long getSum(int x)
{
    long long result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (area[i] > x)
            result += x;
        else
            result += area[i];
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int maxV = 0;
    int totalSum = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> area[i];
        maxV = max(maxV, area[i]);
        totalSum += area[i];
    }

    cin >> M;

    if (totalSum <= M)
    {
        cout << maxV << '\n';
        return 0;
    }

    long long low = 0;
    long long mid;
    long long high = 2000000000;

    while (true)
    {
        mid = (low + high) / 2;

        if (getSum(mid) <= M)
            low = mid;
        else
            high = mid;
        if (high - low <= 1)
            break;
    }

    cout << low << "\n";
    return 0;
}