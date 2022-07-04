#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    arr[0] = 0;
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], arr[i]);

        for (int j = 1; j <= i / 2; j++)
        {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << dp[n];
}