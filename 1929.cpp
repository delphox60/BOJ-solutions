#include <iostream>

using namespace std;

bool pn[1000004];

int main()
{
    int n, m;

    cin >> n >> m;

    pn[1] = false;
    for (int i = 2; i <= 1000003; i++)
        pn[i] = true;
    for (int i = 2; i * i <= m; i++)
    {
        for (int j = i; i * j <= m; j++)
            pn[i * j] = false;
    }

    for (int i = n; i <= m; i++)
    {
        if (pn[i])

            cout << i << "\n";
    }
    return 0;
}