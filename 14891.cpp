#include <iostream>
#include <string>

using namespace std;

int gear[4][8];

int gp[4];
int c = 0;

void rotate(int n, int d, int dir)
{
    if (n < 0 || n > 3)
        return;
    if (n >= 1 && dir < 1)
    {
        if (gear[n][(gp[n] + 6) % 8] == gear[n - 1][(gp[n - 1] + 2) % 8])
            rotate(n - 1, d, -1);
        else
            rotate(n - 1, d * (-1), -1);
    }
    if (n <= 2 && dir > -1)
    {
        if (gear[n][(gp[n] + 2) % 8] == gear[n + 1][(gp[n + 1] + 6) % 8])
            rotate(n + 1, d, 1);
        else
            rotate(n + 1, d * (-1), 1);
    }
    if (d > 0)
        gp[n] = (gp[n] + 7) % 8;
    else
        gp[n] = (gp[n] + 1) % 8;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++)
    {
        string ip;
        cin >> ip;
        for (int j = 0; j < 8; j++)
            gear[i][j] = ip[j] - 48;
        gp[i] = 0;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k, dir;
        cin >> k >> dir;
        rotate(k - 1, dir, 0);
    }

    int result = 0;
    result += gear[0][gp[0]];
    result += gear[1][gp[1]] * 2;
    result += gear[2][gp[2]] * 4;
    result += gear[3][gp[3]] * 8;

    cout << result << '\n';

    for (int i = 0; i < 8; i++)
    {
        cout << gear[0][i] << ' ';
        cout << gear[1][i] << ' ';
        cout << gear[2][i] << ' ';
        cout << gear[3][i] << '\n';
    }
    cout << gp[0] << ' ';
    cout << gp[1] << ' ';
    cout << gp[2] << ' ';
    cout << gp[3] << '\n';

    return 0;
}