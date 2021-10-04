#include <iostream>

using namespace std;

int cmd;
int cmdLen = 1;
int N;
bool button[10];
int minval;

void func(int bef, int k, int length)
{
    if (k == length)
    {
        minval = min(minval, k + (cmd > bef ? cmd - bef : bef - cmd));
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (button[i] == 1)
            func(bef * 10 + i, k + 1, length);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> cmd;
    minval = cmd > 100 ? cmd - 100 : 100 - cmd;

    int tmp = cmd;

    while (true)
    {
        if (tmp / 10)
        {
            cmdLen++;
            tmp /= 10;
        }
        else
            break;
    }

    cin >> N;
    for (int i = 0; i <= 9; i++)
        button[i] = true;

    for (int i = 0; i < N; i++)
    {
        int ip;
        cin >> ip;
        button[ip] = false;
    }

    int length = 6;

    while (length)
    {
        func(0, 0, length);
        length--;
    }
    cout << minval << "\n";

    return 0;
}