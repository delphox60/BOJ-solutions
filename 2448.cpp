#include <iostream>

using namespace std;

bool star(int x, int y, int k)
{
    if (k == 3)
        return ((x == 2 && y != 5) || x + y == 2 || y - x == 2);

    if (x + y >= k - 1 && y - x <= k)
    {
        if (x >= k / 2)
            return star(x % (k / 2), y % k, k / 2);
        else
            return star(x % (k / 2), y - (k / 2), k / 2);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (star(i, j, n))
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}