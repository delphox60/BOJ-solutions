#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[100004];
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int sum[1005];
    int maxof[1005];

    sum[1] = arr[1];
    maxof[1] = sum[1];

    for (int i = 2; i <= n; i++)
    {
        if (sum[i - 1] < 0)
            sum[i] = arr[i];
        else
            sum[i] = sum[i - 1] + arr[i];

        maxof[i] = max(maxof[i - 1], sum[i]);
    }

    cout << maxof[n] << "\n";
    return 0;
}