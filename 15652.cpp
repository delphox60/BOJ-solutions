#include <iostream>

using namespace std;

int n, m;
int arr[8];

void func(int k, int bef)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i >= bef)
        {
            arr[k] = i;
            func(k + 1, i);
        }
    }

    return;
}

int main()
{
    cin >> n >> m;

    func(0, 0);
    return 0;
}