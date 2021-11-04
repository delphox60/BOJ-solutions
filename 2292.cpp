#include <iostream>

using namespace std;

int layer(int n)
{
    return 1 + (n * (n - 1) / 2) * 6;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int tmp = 1;

    while (n > layer(tmp))
    {
        tmp++;
    }
    cout << tmp << '\n';

    return 0;
}