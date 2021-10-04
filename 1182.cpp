#include <iostream>

using namespace std;

int N, S;
int cnt = 0;
int result = 0;
int used[20];

void func(int set[], int m, int k, int bef)
{
    if (k == m)
    {
        if (result == S)
            cnt++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!used[i] && i > bef)
        {
            result += set[i];
            used[i] = 1;
            func(set, m, k + 1, i);
            result -= set[i];
            used[i] = 0;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    int uset[N];

    for (int i = 0; i < N; i++)
    {
        cin >> uset[i];
    }

    for (int i = 1; i <= N; i++)
    {
        used[i] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
        func(uset, i, 0, -1);
    }

    cout << cnt << "\n";

    return 0;
}