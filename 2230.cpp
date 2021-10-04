#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int result = 2000000005;
    int tmp = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
    {
        while (tmp < N && arr[tmp] - arr[i] < M)
            tmp++;
        if (tmp == N)
            break;
        result = min(result, arr[tmp] - arr[i]);
    }

    cout << result << "\n";
    return 0;
}