#include <iostream>

using namespace std;

int arr[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    long long result = 100001;
    long long tmp = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ep = 0;
    int sp = 0;

    tmp = arr[0];

    while (ep <= N)
    {
        if (tmp >= M && ep - sp + 1 < result)
            result = ep - sp + 1;
        if (ep == N)
            break;
        if (tmp < M)
        {
            ep++;
            tmp += arr[ep];
        }
        else
        {
            tmp -= arr[sp];
            sp++;
        }
    }

    if (result == 100001)
    {
        cout << 0 << "\n";
        return 0;
    }
    cout << result << "\n";
    return 0;
}