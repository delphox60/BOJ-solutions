#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double arr[10000];
    double table[10000];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    double result = arr[0];
    table[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        table[i] = max(arr[i], arr[i] * table[i - 1]);
        result = max(result, table[i]);
    }

    printf("%.3f", result);
}