#include <iostream>

int main()
{
    using namespace std;
    int n, m;
    cin >> n >> m;

    char field[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> field[i][j];
        }
    }

    int square_size;
    if (n >= m)
        square_size = m;
    else
        square_size = n;
    while (1)
    {
        if (square_size == 1)
        {
            cout << 1 << endl;
            return 0;
        }
        for (int j = 0; j + square_size - 1 < n; j++)
        {
            for (int i = 0; i + square_size - 1 < m; i++)
            {
                if (field[j][i] == field[j + square_size - 1][i] &&
                    field[j][i] == field[j][i + square_size - 1] &&
                    field[j][i] == field[j + square_size - 1][i + square_size - 1])
                {
                    cout << square_size * square_size << endl;
                    return 0;
                }
            }
        }
        square_size--;
    }

    return 0;
}