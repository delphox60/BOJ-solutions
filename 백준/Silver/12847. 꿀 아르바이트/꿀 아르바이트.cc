#include <iostream>

using namespace std;

int arr[1000000];
long long dp[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    cin >> arr[0];
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = arr[i] + dp[i - 1];
    }

    long long result = dp[m - 1];

    for (int i = m; i < n - 1; i++)
    {
        result = max(result, dp[i] - dp[i - m]);
    }
    cout << result;
}