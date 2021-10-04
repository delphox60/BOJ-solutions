#include <iostream>
#include <string>

using namespace std;

int used[7];
int result[7];

void func(int k, int n, int m, int front)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {

        result[k] = (i + 1);

        func(k + 1, n, m, i + 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        used[i] = 0;
    }

    func(0, n, m, 0);
    return 0;
}