#include <iostream>

using namespace std;

bool star(int x, int y, int k)
{
    if (k == 1)
        return (x != 1 || y != 1);
    k /= 3;
    if (x / k == 1 && y / k == 1)
        return false;
    x %= k;
    y %= k;
    return star(x, y, k);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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