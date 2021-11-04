#include <iostream>

using namespace std;

int arr[1005];
int dp_a[1005];
int dp_d[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp_a[i] = 1;
        dp_d[i] = 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp_a[i] = max(dp_a[j] + 1, dp_a[i]);
        }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                dp_d[i] = max(dp_d[j] + 1, dp_d[i]);
        }

    int result = 1;

    for (int i = 0; i < n; i++)
    {
        result = max(result, dp_a[i] + dp_d[i] - 1);
    }
    cout << result << '\n';
    return 0;
}
