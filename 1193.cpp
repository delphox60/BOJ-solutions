#include <iostream>

int layer(int a)
{
    int base = 0;
    while ((base + 2) * (base + 1) / 2 < a)
        base++;
    return base;
}

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    cin >> X;

    int l = layer(X);
    X -= l * (l + 1) / 2;
    l += 1;
    if (l % 2)
        cout << l - X + 1 << '/' << X << '\n';
    else
        cout << X << '/' << l - X + 1 << '\n';
    return 0;
}