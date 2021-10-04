#include <iostream>

int main()
{
    using namespace std;
    int n_stick = 0;
    int A, B;
    int field[100];

    for (int i = 0; i < 100; i++)
    {
        char x;
        cin >> x;
        if (x == '-' || x == '|')
        {
            field[i] = 1;
            n_stick++;
        }
        else
            field[i] = 0;
    }
    A = 24 - n_stick / 2;
    B = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field[30 * i + 3 * j + 1] &&
                field[30 * i + 3 * j + 10] && field[30 * i + 3 * j + 13] && field[30 * i + 3 * j + 31])
                B++;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (field[30 * i + 3 * j + 1] &&
                field[30 * i + 3 * j + 4] &&
                field[30 * i + 3 * j + 10] &&
                field[30 * i + 3 * j + 40] &&
                field[30 * i + 3 * j + 16] &&
                field[30 * i + 3 * j + 46] &&
                field[30 * i + 3 * j + 61] &&
                field[30 * i + 3 * j + 64])
                B++;
        }
    }
    if (field[1] && field[4] && field[7] && field[10] && field[40] && field[70] && field[19] && field[49] && field[79] && field[91] && field[94] && field[97])
        B++;

    cout << A << " " << B << endl;
    return 0;
}