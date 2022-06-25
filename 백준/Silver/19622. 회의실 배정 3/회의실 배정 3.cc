#include <iostream>

using namespace std;

int n;
int arr[100000];
int table[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int s, e;
    for (int i = 0; i < n; i++)
        cin >> s >> e >> arr[i];

    if (n == 1)
    {
        cout << arr[0];
        return 0;
    }

    table[0] = arr[0];
    table[1] = max(table[0], arr[1]);
    for (int i = 1; i < n; i++)
        table[i] = max(table[i - 1], arr[i] + table[i - 2]);

    cout << table[n - 1];
}