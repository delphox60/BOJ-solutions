#include <iostream>

using namespace std;

int N;
int H[1000005];
int M;

long long getWood(int h)
{
    long long result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (H[i] > h)
            result += (H[i] - h);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> H[i];
    }

    long long low = 0;
    long long high = 2000000000;
    long long mid;

    while (true)
    {
        mid = (low + high) / 2;
        if (getWood(mid) >= M)
        {
            low = mid;
        }
        else
            high = mid;
        if (high - low <= 1)
            break;
    }

    cout << low << "\n";
    return 0;
}