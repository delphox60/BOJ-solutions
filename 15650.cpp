#include <iostream>

using namespace std;

bool used[8];
int op[8];

void func(int k, int n, int m, int front)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << op[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i] && i + 1 > front)
        {
            op[k] = i + 1;
            used[i] = 1;
            func(k + 1, n, m, i + 1);
            used[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 8; i++)
    {
        used[i] = 0;
    }

    func(0, n, m, 0);
    return 0;
}