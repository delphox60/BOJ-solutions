#include <iostream>

using namespace std;

int d[100005];
int arr[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    d[0] = 0;
    d[1] = arr[1];

    for (int i = 2; i <= n; i++)
        d[i] = d[i - 1] + arr[i];

    for (int i = 0; i < m; i++)
    {
        int low, high;
        cin >> low >> high;

        cout << d[high] - d[low - 1] << "\n";
    }
    return 0;
}