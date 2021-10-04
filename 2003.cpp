#include <iostream>

using namespace std;

int arr[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    long long tmp = 0;
    int result = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ep = 0;
    int sp = 0;
    tmp = arr[ep];

    while (ep < N)
    {
        if (tmp < M)
        {
            ep++;
            tmp += arr[ep];
        }
        else
        {
            if (tmp == M)
                result++;
            tmp -= arr[sp];
            sp++;
        }
    }
    cout << result << '\n';
    return 0;
}