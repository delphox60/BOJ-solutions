#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];

int table[2][100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n == 1)
    {
        cout << arr[0];
        return 0;
    }

    table[0][0] = arr[0];
    table[1][0] = 0;

    for (int i = 1; i < n; i++)
    {
        table[0][i] = max(table[0][i - 1], 0) + arr[i];
        table[1][i] = max(table[1][i - 1] + arr[i], table[0][i - 1]);
    }

    cout << max(*max_element(table[0], table[0] + n), *max_element(table[1] + 1, table[1] + n));
}