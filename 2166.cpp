#include <iostream>
#include <cmath>
#define point pair<int, int>
#define X first
#define Y second
#define ld long double

using namespace std;

point polygon[10005];
ld result = 0;

ld crs_product(point a, point b)
{
    int x = polygon[0].X;
    int y = polygon[0].Y;

    return ((long long)(a.X - x) * (long long)(b.Y - y) - (long long)(a.Y - y) * (long long)(b.X - x)) / 2.0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        polygon[i] = {a, b};
    }

    for (int i = 1; i < n - 1; i++)
        result += crs_product(polygon[i], polygon[i + 1]);

    if (result < 0)
        result *= -1;
    cout << fixed;
    cout.precision(1);
    cout << round(result * 10.0) / 10.0;
}
