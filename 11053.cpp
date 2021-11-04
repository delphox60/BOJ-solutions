#include <iostream>

using namespace std;

int arr[1005];
int dp[1005];
int maxval = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxval = max(maxval, dp[i]);
    }
    cout << maxval << '\n';
    return 0;
}