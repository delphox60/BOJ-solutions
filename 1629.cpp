#include <iostream>

using namespace std;

using ll = long long;

ll func(ll x, ll y, ll z)
{
    if (y == 1)
    {
        return x % z;
    }

    ll result = func(x, y / 2, z);
    result = result * result % z;

    if (y % 2 == 0)
        return result;
    return result * x % z;
}

int main()
{
    int A, B, C;

    cin >> A >> B >> C;

    cout << func(A, B, C) << "\n";

    return 0;
}