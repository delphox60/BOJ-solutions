#include <iostream>
#include <cstring>

int main()
{
    using namespace std;

    int standard[8][8] = {
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};

    int n, m;
    cin >> n >> m;
    char board[n][m];

    int min_n_wrong = 64;

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
            board[i][j] = line[j];
    }

    for (int k = 0; k < n - 7; k++)
        for (int l = 0; l < m - 7; l++)
        {
            int n_wrong = 64;

            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    if (standard[i][j] == board[k + i][l + j])
                        n_wrong--;
                }
            if (n_wrong > 32)
                n_wrong = 64 - n_wrong;
            if (n_wrong < min_n_wrong)
                min_n_wrong = n_wrong;
        }
    cout << min_n_wrong << endl;
    return 0;
}