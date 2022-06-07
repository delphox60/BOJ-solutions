#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int arr[1000];
    int table[1000];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        table[i] = 1;
    }

    int result = table[0];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
            {
                table[i] = max(table[j] + 1, table[i]);
                result = max(result, table[i]);
            }
    cout << result << endl;

}