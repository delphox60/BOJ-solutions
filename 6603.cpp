#include <iostream>

using namespace std;

int n;
int arr[6];
int used[13];

void func(int set[], int k, int bef)
{
    if (k == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i] && i > bef)
        {
            used[i] = 1;
            arr[k] = set[i];
            func(set, k + 1, i);
            used[i] = 0;
        }
    }

    return;
}

int main()
{
    for (int i = 0; i < 13; i++)
        used[i] = 0;

    while (true)
    {
        cin >> n;

        if (n == 0)
            break;

        int set[n];
        for (int i = 0; i < n; i++)
        {
            cin >> set[i];
        }
        func(set, 0, -1);
        cout << "\n";
    }
    return 0;
}