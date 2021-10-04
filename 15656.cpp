#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int list[8];
int result[8];
int used[8];

void func(int k, int bef)
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
        if ()
        result[k] = list[i];
        used[i] = 1;
        func(k + 1, i);
        used[i] = 0;
    }
    return;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
        used[i] = 0;
    }

    sort(list, list + n);

    func(0, -1);
    return 0;
}