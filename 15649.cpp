#include <iostream>
using namespace std;
int n, m;
int arr[10];
bool used[10];

void nm(int k)
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
        if (!used[i])
        {
            arr[k] = i;
            used[i] = 1;
            nm(k + 1);
            used[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    nm(0);
    return 0;
}