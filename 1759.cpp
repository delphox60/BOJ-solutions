#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char arr[15];
int used[15];
int cond1 = 0;

bool ismoeum(char x)
{
    if (x == 'a' ||
        x == 'e' ||
        x == 'i' ||
        x == 'o' ||
        x == 'u')
        return true;
    return false;
}

void func(char list[], int k, char bef)
{
    if (k == L && cond1 >= 1 && L - cond1 >= 2)
    {
        for (int i = 0; i < L; i++)
            cout << arr[i];
        cout << "\n";
        return;
    }

    for (int i = 0; i < C; i++)
    {
        if (!used[i] && list[i] > bef)
        {
            used[i] = 1;

            if (ismoeum(list[i]))
                cond1++;

            arr[k] = list[i];

            func(list, k + 1, list[i]);

            used[i] = 0;

            if (ismoeum(list[i]))
                cond1--;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 15; i++)
        used[i] = 0;

    cin >> L >> C;

    char list[C];

    for (int i = 0; i < C; i++)
        cin >> list[i];

    sort(list, list + C);

    func(list, 0, 0);

    return 0;
}